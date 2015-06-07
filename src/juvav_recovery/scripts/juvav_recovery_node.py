#! /usr/bin/env python

import rospy
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs.point_cloud2 as pc2
from geometry_msgs.msg import Twist, Vector3
from nav_msgs.msg import Path, Odometry, OccupancyGrid
from map_msgs.msg import OccupancyGridUpdate

import tf
from cv_bridge import CvBridge
from math import *
from juvav_recovery.srv import *

from numpy import array
from numpy.linalg import inv

from collections import deque
import copy

undo_cmd_vel = False
undo_cmd_vel_time = 0.0


class Position(object):
    def __init__(self, trans, yaw):
        self.trans = trans
        self.yaw = yaw


class BehaviorAnalyzer:

    INVALID_CMD_VALUE = ((), ())

    def __init__(self):
        self.last_cmd_vel_values = deque((Twist(),), 20)
        self.last_cmd_vel_values.pop()

        self.last_tf_values = deque(((tuple(), tuple(), tuple()),), 10)
        self.last_tf_values.pop()

        self.last_local_path_values = deque((Path(),), 10)
        self.last_local_path_values.pop()

        self.last_cmd_vel_time = deque((float(),), 10)
        self.last_cmd_vel_time.pop()

        self.last_tf_time = deque((float(),), 10)
        self.last_tf_time.pop()

        self.last_local_path_time = deque((float(),), 10)
        self.last_local_path_time.pop()

    def is_undo_needed(self):
        global undo_cmd_vel
        current_time = rospy.get_time()
        try:
            #((trans_x, trans_y, trans_z), (rot_quat_x, rot_quat_y, rot_quat_), ()) = self.last_tf_values[0]



            """

            reculer pendant au moins 2 secondes
            """

            if len(self.last_local_path_values[0].poses) < 5:
                return True

            if current_time - self.last_cmd_vel_time[0] > 3.0:
                return True

            if current_time - self.last_local_path_time[0] > 3.0:
                nb_invalid_cmd_vel = True



                last_twist_msgs = [self.last_cmd_vel_values[i] for i in xrange(3)]
                for lin_x, lin_y, lin_z, ang_x, ang_y, ang_z in [(twist.linear.x, twist.linear.y, twist.linear.z,
                                                                  twist.angular.x, twist.angular.y, twist.angular.z)
                                                                 for twist in copy.deepcopy(last_twist_msgs)]:
                    if ((lin_x, lin_y, lin_z), (ang_x, ang_y, ang_z)) == ((0.0, 0.0, 0.0), (0.0, 0.0, 0.0)):
                        nb_invalid_cmd_vel += 1

                if nb_invalid_cmd_vel > 3:
                    return True

            #if current_time - self.last_cmd_vel_time[0] > 0.5:
           #     return True

           # if undo_cmd_vel:

            #    if len(self.last_local_path_values[0].poses) > 5:
           #         return False

           #     if current_time - self.last_cmd_vel_time[0] > 0.5:
           #         return False

           # else:

                #nb_invalid_cmd_vel = 0
                #last_twist_msgs = [self.last_cmd_vel_values[i] for i in xrange(3)]
                #for lin_x, lin_y, lin_z, ang_x, ang_y, ang_z in [(twist.linear.x, twist.linear.y, twist.linear.z,
                #                                                 twist.angular.x, twist.angular.y, twist.angular.z)
                #                                                 for twist in last_twist_msgs]:
                #    if ((lin_x, lin_y, lin_z), (ang_x, ang_y, ang_z)) == ((0.0, 0.0, 0.0), (0.0, 0.0, 0.0)):
                 #       nb_invalid_cmd_vel += 1

                #if nb_invalid_cmd_vel < 3:
                #    #print 'Warning: {} invalid twist cmd_vel in a row since good behavior'.format(nb_invalid_cmd_vel)
                #    return False




            #last_local_paths = [ for i in xrange(1)]
            #nb_valid_local_paths = 0
            #for local_path in last_local_paths:
            #    if len(local_path) > 5:
            #        nb_valid_local_paths += 1


            #if nb_valid_local_paths > 0:
            #    return False

            #print current_time - self.last_cmd_vel_time[0], current_time - self.last_tf_time[0], \
            #    current_time - self.last_local_path_time[0]

            #nb_invalid_elapsed_time = 0
            #cmd_vel_elapsed_times = [current_time - last_time for last_time in
            #                         [self.last_cmd_vel_time[i] for i in xrange(8)]]
            #for elapsed_time in cmd_vel_elapsed_times:
            #    if elapsed_time > 1.5:
            #        nb_invalid_elapsed_time += 1

            #if nb_invalid_elapsed_time > 0:
                #print 'Warning: {} invalid cmd_vel elapsed time since good behavior'.format(nb_invalid_elapsed_time)
                #return True
            #    pass

            return False
        except IndexError:
            pass


class JuvavRecoveryNode:


    def __init__(self):

        self.precision_x = rospy.get_param('/juvav_recovery_node/precision_x')
        self.precision_yaw = rospy.get_param('/juvav_recovery_node/precision_yaw')

        self.max_accel_x = rospy.get_param('/juvav_recovery_node/max_accel_x')
        self.min_accel_x = rospy.get_param('/juvav_recovery_node/min_accel_x')
        self.accel_x_mult_factor = rospy.get_param('/juvav_recovery_node/accel_x_mult_factor')

        self.max_accel_yaw = rospy.get_param('/juvav_recovery_node/max_accel_yaw')
        self.min_accel_yaw = rospy.get_param('/juvav_recovery_node/min_accel_yaw')
        self.accel_yaw_mult_factor = rospy.get_param('/juvav_recovery_node/accel_yaw_mult_factor')

        self.map_width = rospy.get_param('/juvav_recovery_node/juvav_map_width')
        self.map_height = rospy.get_param('/juvav_recovery_node/juvav_map_height')

        self.nb_cmd_vel_zeros = rospy.get_param('/juvav_recovery_node/nb_zeros_between_states')

        self.cmd_vel_zeros_stack = []
        self.last_cmd_vel_twist = Twist(linear=Vector3(x=0.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=0.0))
        self.last_cmd_vel_was_reversed = False

        self.undo_stack = deque((Odometry,), 100)
        self.undo_stack.pop()
        self.requested_vel = None
        self.requested_vel_time = 0

        self.last_cmd_vel_from_move_base = 0.0
        self.last_cmd_vel_from_juvav = 0.0

        self.local_path_analyzer = BehaviorAnalyzer()

        rospy.init_node('juvav_recovery_node', log_level=rospy.INFO)
        s_run = rospy.Service('juvav_recovery_node/run', Run, self.handle_run)

        self.smart_cmd_vel_publisher = rospy.Publisher('/smart_cmd_vel', Twist, queue_size=10)
        rospy.Subscriber('/cmd_vel', Twist, self.cmd_vel_callback)
        rospy.Subscriber('/move_base/TrajectoryPlannerROS/local_plan', Path, self.local_path_callback)
        rospy.Subscriber('/odom', Odometry, self.odom_callback)
        rospy.Subscriber('/move_base/local_costmap/costmap', OccupancyGrid, self.costmap_callback)

        self.tf_listener = tf.TransformListener()

        global undo_cmd_vel
        last_time = rospy.get_time()

        count = 0

        rate = rospy.Rate(20)  # 4Hz
        while not rospy.is_shutdown():
            current_time = rospy.get_time()

            try:

                if count == 200:
                    #count = 0
                    undo_cmd_vel = True
                    print 'JUVAV!!'
                count += 1

                if undo_cmd_vel and rospy.get_time() - self.last_cmd_vel_from_move_base > 0.5:
                    self.publish_smart_cmd_vel(None)
                    #print '{}({}) {}({})'.format(
                    #   self.last_cmd_vel_from_move_base, rospy.get_time() - self.last_cmd_vel_from_move_base,
                    #   self.last_cmd_vel_from_juvav, rospy.get_time() - self.last_cmd_vel_from_juvav,)


                #print id(self.local_path_analyzer.last_cmd_vel_values)
                #print id(copy.deepcopy(self.local_path_analyzer.last_cmd_vel_values))
                """
                if current_time - self.local_path_analyzer.last_cmd_vel_time[0] > 3.0:
                    undo_cmd_vel = self.local_path_analyzer.is_undo_needed()
                    self.publish_smart_cmd_vel(None)

                invalid_cmd_vel_stack = True
                for lin_x, lin_y, lin_z, ang_x, ang_y, ang_z in [
                    (twist.linear.x, twist.linear.y, twist.linear.z, twist.angular.x, twist.angular.y, twist.angular.z)
                        for twist in copy.deepcopy(self.local_path_analyzer.last_cmd_vel_values)]:

                    if ((lin_x, lin_y, lin_z), (ang_x, ang_y, ang_z)) != ((0.0, 0.0, 0.0), (0.0, 0.0, 0.0)):
                        invalid_cmd_vel_stack = False

                if invalid_cmd_vel_stack:
                    undo_cmd_vel = self.local_path_analyzer.is_undo_needed()
                    self.publish_smart_cmd_vel(None)
                """
            except IndexError:
                pass

            #is_undo_needed = self.local_path_analyzer.is_undo_needed()
            #if is_undo_needed != undo_cmd_vel:
            #    undo_cmd_vel = is_undo_needed

            #if is_undo_needed and rospy.get_time() - self.local_path_analyzer.last_cmd_vel_time[0] > 0.2:
            #    self.publish_smart_cmd_vel(None)

            rate.sleep()

    @staticmethod
    def handle_run(msg):
        global undo_cmd_vel
        undo_cmd_vel = True
        return True

    def publish_smart_cmd_vel(self, event):

        def get_current_x_y_yaw():
            """
            :return: (float, float, float)
            """
            ((_x, _y, _z), _rotQ) = self.tf_listener.lookupTransform('/base_footprint', '/odom', rospy.Time(0))
            _yaw = tf.transformations.euler_from_quaternion(_rotQ)[2]

            return -_x + self.map_width / 2.0, -_y + self.map_height / 2.0, _yaw

        global undo_cmd_vel, undo_cmd_vel_time

        if undo_cmd_vel:
            self.last_cmd_vel_from_juvav = rospy.get_time()

        current_time = rospy.get_time()

        if undo_cmd_vel:
            try:

                twist_found = False
                skipped_twist_str = ''

                new_x = new_yaw = 0.0
                current_x = current_yaw = 0.0
                target_x = target_yaw = 0.0
                while not twist_found:
                    (current_x, current_y, current_yaw) = get_current_x_y_yaw()
                    (target_x, target_y, target_yaw) = self.undo_stack[-1]


                    if abs(current_yaw - target_yaw) > self.precision_yaw:
                        new_yaw = (current_yaw - target_yaw) * self.accel_yaw_mult_factor
                        twist_found = True

                    else:
                        if abs(target_x - current_x) > self.precision_x:
                            new_x = (target_x - current_x) * self.accel_x_mult_factor
                            twist_found = True

                        else:
                            t_x, t_y, t_yaw = self.undo_stack.pop()
                            print '[{}, {}, {}]'.format(t_x, t_y, t_yaw)
                            skipped_twist_str += '.'

                print skipped_twist_str

                ### print '({} {}) = {}'.format(current_x - target_x, target_x - current_x, new_x)

                # validate min_max accel for both x and yaw
                if new_x != 0.0:
                    if abs(new_x) < self.min_accel_x:
                        new_x = copysign(self.min_accel_x, new_x)

                    if abs(new_x) > self.max_accel_x:
                        new_x = copysign(self.max_accel_x, new_x)

                if new_yaw != 0.0:
                    if abs(new_yaw) < self.min_accel_yaw:
                        new_yaw = copysign(self.min_accel_yaw, new_yaw)

                    if abs(new_yaw) > self.max_accel_yaw:
                        new_yaw = copysign(self.max_accel_yaw, new_yaw)

                # check if state change occured
                if self.last_cmd_vel_twist.linear.x != 0.0:
                    if self.last_cmd_vel_was_reversed and \
                            copysign(1.0, self.last_cmd_vel_twist.linear.x) != copysign(1.0, new_x):
                        print '--1'

                        while len(self.cmd_vel_zeros_stack) < self.nb_cmd_vel_zeros:
                            self.cmd_vel_zeros_stack.append(Twist(linear=Vector3(x=0.0, y=0.0, z=0.0),
                                                                  angular=Vector3(x=0.0, y=0.0, z=0.0)))

                if self.last_cmd_vel_twist.angular.z != 0.0:
                    if self.last_cmd_vel_was_reversed and \
                            copysign(1.0, self.last_cmd_vel_twist.angular.z) != copysign(1.0, new_yaw):
                        print '--2'
                        while len(self.cmd_vel_zeros_stack) < self.nb_cmd_vel_zeros:
                            self.cmd_vel_zeros_stack.append(Twist(linear=Vector3(x=0.0, y=0.0, z=0.0),
                                                                  angular=Vector3(x=0.0, y=0.0, z=0.0)))

                if not self.last_cmd_vel_was_reversed and len(self.cmd_vel_zeros_stack) == 0:
                    print '--3'
                    while len(self.cmd_vel_zeros_stack) < self.nb_cmd_vel_zeros:
                            self.cmd_vel_zeros_stack.append(Twist(linear=Vector3(x=0.0, y=0.0, z=0.0),
                                                                  angular=Vector3(x=0.0, y=0.0, z=0.0)))

                # pop cmd_vel_zeros if any
                if len(self.cmd_vel_zeros_stack) > 0:
                    twist = self.cmd_vel_zeros_stack.pop()
                    ### print 'cmd_vel_zeros', '({}, {})'.format(new_x, new_yaw)

                else:
                    twist = Twist(
                        linear=Vector3(x=new_x, y=0.0, z=0.0),
                        angular=Vector3(x=0.0, y=0.0, z=new_yaw))

                    ### print '({4}{0:.5f} -{8}-> {1:.5f}{5}, {6}{2:.5f} -{9}-> {3:.5f}{7})'.format(
                    ###     current_x, target_x, current_yaw, target_yaw,
                    ###     '[' if new_x != 0.0 else '', ']' if new_x != 0.0 else '',
                    ###     '[' if new_yaw != 0.0 else '', ']' if new_yaw != 0.0 else '',
                    ###     '|{}|'.format(new_x) if new_x != 0.0 else '',
                    ###     '|{}|'.format(new_yaw) if new_yaw != 0.0 else ''
                    ### )

                # publish twist msg
                self.smart_cmd_vel_publisher.publish(twist)
                self.last_cmd_vel_was_reversed = True
                self.last_cmd_vel_twist = twist

                #
                #print '({} - {}, {}, {})'.format(target_x, current_y, current_yaw)

                #print '({:.4f} + {:.4f}({:.4f}) = {:.4f}, 0.0, {:.4f} + {:.4f}({:.4f}) = {:.4f})\n'.format(
                #    current_x, current_x - target_x, new_x, target_x,
                #    current_yaw, current_yaw - target_yaw, new_yaw, target_yaw)

                #print '({}, {}, {})'.format(target_x - current_x,
                #                            target_y - current_y,
                #                            target_yaw - current_yaw)
                #print '({}, {}, {})'.format(twist.linear.x, twist.linear.y, twist.angular.z)
                #print 'publishing undo cmd_vel msg on /smart_cmd_vel'

            except IndexError:
                undo_cmd_vel = False
                #undo_cmd_vel_time = 0.0
        else:
            try:

                (x, y, yaw) = get_current_x_y_yaw()

                if self.last_cmd_vel_was_reversed:
                    print '--4'
                    while len(self.cmd_vel_zeros_stack) < self.nb_cmd_vel_zeros:
                            self.cmd_vel_zeros_stack.append(Twist(linear=Vector3(x=0.0, y=0.0, z=0.0),
                                                                  angular=Vector3(x=0.0, y=0.0, z=0.0)))

                if len(self.cmd_vel_zeros_stack) > 0:
                    twist = self.cmd_vel_zeros_stack.pop()

                else:
                    self.undo_stack.append((x, y, yaw))
                    twist = self.requested_vel

                    self.last_cmd_vel_twist = self.requested_vel
                    self.last_cmd_vel_was_reversed = False

                    self.local_path_analyzer.last_cmd_vel_values.append(self.requested_vel)
                    self.local_path_analyzer.last_cmd_vel_time.append(rospy.get_time())

                self.smart_cmd_vel_publisher.publish(twist)

                print '({:.5f}, {:.5f}, {:.5f})'.format(x, y, yaw)

                #print '.'

                (last_trans_x, last_trans_y, last_yaw) = self.undo_stack[1]

                #print '({}, {}, {})'.format(trans_x, trans_y, yaw)
                #print '({}, {}, {})'.format(trans_x - last_trans_x, trans_y - last_trans_y, yaw - last_yaw)
                #print '(({}, {}, {}) ({}, {}, {}))'.format(
                #    self.requested_vel.linear.x, self.requested_vel.linear.y, self.requested_vel.linear.z,
                #    self.requested_vel.angular.x, self.requested_vel.angular.y, self.requested_vel.angular.z)
            except IndexError:
                pass

    def cmd_vel_callback(self, msg):
        self.requested_vel = msg
        self.requested_vel_time = rospy.get_time()
        self.publish_smart_cmd_vel(None)
        self.last_cmd_vel_from_move_base = rospy.get_time()

    def odom_callback(self, msg):
        type(msg)

    def costmap_callback(self, msg):
        x = msg.info.origin.position.x
        y = msg.info.origin.position.y
        w = msg.info.width
        h = msg.info.height

        if x < 0:
            if y < 0:   # (-x, -y)
                x = abs(x)
                y = abs(y) + h / 2.0
            else:       # (-x, y)
                x = abs(x)
                y -= h / 2.0
        else:
            if y < 0:   # (x, -y)
                x += w / 2.0
                y = abs(y) + h / 2.0
            else:       # (x, y)
                x += w / 2.0
                y -= h / 2.0

        x = int(round(x))
        y = int(round(y))
        index = w * y + x

        #print x, y, index, msg.data[index]

        ##print type(msg.data[int(round(y, 0))])##[int(round(x, 0))]

        #print len(msg.data)

        #print msg.data[len(msg.data) / 2]

    def local_path_callback(self, msg):
        """
        :param msg:
        :return:
        """

        global undo_cmd_vel

        (trans, rotQ) = self.tf_listener.lookupTransform('/base_footprint', '/odom', rospy.Time(0))
        rotE = tf.transformations.euler_from_quaternion(rotQ)

        self.local_path_analyzer.last_tf_values.append((trans, rotQ, rotE))
        self.local_path_analyzer.last_tf_time.append(rospy.get_time())

        self.local_path_analyzer.last_local_path_values.append(msg)
        self.local_path_analyzer.last_local_path_time.append(rospy.get_time())

if __name__ == "__main__":
    try:
        s = JuvavRecoveryNode()
    except rospy.ROSInterruptException:
        pass



"""


"""


"""

(trans_x, trans_y, yaw)
(lin_x, lin_y, lin_z) (ang_x, ang_y, ang_z)


(-22.5, 40.0, 0.0)
((0.1, 0.0, 0.0) (0.0, 0.0, 0.0))

(-22.5, 40.0, 0.0)
((0.1, 0.0, 0.0) (0.0, 0.0, 0.0))

(-22.5102, 40.0, 0.0)
((0.1, 0.0, 0.0) (0.0, 0.0, 0.0))

(-22.5102, 40.0, 0.0)
((0.131578947761, 0.0, 0.0) (0.0, 0.0, 0.328421052632))

(-22.4366247473, 40.0443011545, -0.00197052630128)
((0.126045207224, 0.0, 0.0) (0.0, 0.0, 0.266006193255))

(-21.2332658587, 40.702385129, -0.0320990710925)
((0.171635558041, 0.0, 0.0) (0.0, 0.0, 0.653170641598))

(-21.2332658587, 40.702385129, -0.0320990710925)
((0.163676051592, 0.0, 0.0) (0.0, 0.0, 0.653170641598))

(-18.6069548211, 41.9763946566, -0.0960123232951)
((0.225924684217, 0.0, 0.0) (0.0, 0.0, 0.72634615208))

(-17.0816746966, 42.6246483027, -0.132324220503)
((0.21594361644, 0.0, 0.0) (0.0, 0.0, 0.678433803132))

(-15.6017559516, 43.1926970395, -0.167068080292)
((0.272121228293, 0.0, 0.0) (0.0, 0.0, 0.787787399919))

(-13.8823368188, 43.7804815874, -0.206917174914)
((0.296709975192, 0.0, 0.0) (0.0, 0.0, 0.636208452551))

(-12.3016472692, 44.2551447431, -0.243153278328)
((0.350752635881, 0.0, 0.0) (0.0, 0.0, 0.655039174306))

(-10.8722609715, 44.631992941, -0.275656400645)
((0.379256305883, 0.0, 0.0) (0.0, 0.0, 0.0))

(-9.8545054718, 44.8762415723, -0.299237810139)
((0.407139223312, 0.0, 0.0) (0.0, 0.0, 0.0))

(-9.8747119139, 44.8762415725, -0.299237810139)
((0.461361571237, 0.0, 0.0) (0.0, 0.0, 0.176842105263))

(-9.74566648151, 44.9092471802, -0.302597810179)
((0.478310002967, 0.0, 0.0) (0.0, 0.0, 0.0757894736842))

"""

"""
(0.0, 0.0, 0.0)
((0.1, 0.0, 0.0) (0.0, 0.0, 0.0))

(0.0, 0.0, 0.0)
((0.1, 0.0, 0.0) (0.0, 0.0, 0.0))

(0.0102, 0.0, 0.0)
((0.145696595797, 0.0, 0.0) (0.0, 0.0, 0.429473684211))

(-0.77717326605, -0.437148398642, 0.0197557891943)
((0.125263158208, 0.0, 0.0) (0.0, 0.0, 0.378947368421))

(-1.59717794708, -0.870805152925, 0.0400926310761)
((0.167866120087, 0.0, 0.0) (0.0, 0.0, 0.564210545891))

(-2.75024981739, -1.44471621223, 0.0683115787134)
((0.16452275753, 0.0, 0.0) (0.0, 0.0, 0.52507738973))

[ WARN] [/move_base] [1433094397.317602629, 3627.277000000]: Map update loop missed its desired rate of 10.0000Hz... the loop actually took 0.1130 seconds
(-3.88487993528, -1.97072173465, 0.0957166555119)
((0.156457412839, 0.0, 0.0) (0.0, 0.0, 0.47455107394))
[ WARN] [/move_base] [1433094397.424562237, 3627.343000000]: Control loop missed its desired rate of 20.0000Hz... the loop actually took 0.0570 seconds
(-4.9087106985, -2.41370022787, 0.120171391483)
((0.217161066407, 0.0, 0.0) (0.0, 0.0, 0.714196514958))
(-6.20810460098, -2.93369669637, 0.150843922241)
((0.211913103304, 0.0, 0.0) (0.0, 0.0, 0.706873036121))
(-7.75878476812, -3.49475525561, 0.186975003905)
((0.19326091942, 0.0, 0.0) (0.0, 0.0, 0.706873036121))
[ WARN] [/move_base] [1433094397.602971399, 3627.438000000]: Control loop missed its desired rate of 20.0000Hz... the loop actually took 0.0520 seconds
[ WARN] [/move_base] [1433094397.728284941, 3627.519000000]: Control loop missed its desired rate of 20.0000Hz... the loop actually took 0.0830 seconds
(-9.32596069382, -3.99835867725, 0.223025527375)
((0.264610040972, 0.0, 0.0) (0.0, 0.0, 0.727737920535))
[ WARN] [/move_base] [1433094397.829697500, 3627.573000000]: Control loop missed its desired rate of 20.0000Hz... the loop actually took 0.0870 seconds
(-10.916485376, -4.44683746946, 0.259222105082)
((0.248833033788, 0.0, 0.0) (0.0, 0.0, 0.681609960983))
[ WARN] [/move_base] [1433094397.832576361, 3627.574000000]: Map update loop missed its desired rate of 10.0000Hz... the loop actually took 0.1100 seconds
(-14.1039308845, -5.16406419027, 0.330914332602)
((0.275997794616, 0.0, 0.0) (0.0, 0.0, 0.98763120325))
[ WARN] [/move_base] [1433094397.986110276, 3627.671000000]: Control loop missed its desired rate of 20.0000Hz... the loop actually took 0.1350 seconds
(-15.8880864381, -5.46211991337, 0.370572778396)
((0.343444717715, 0.0, 0.0) (0.0, 0.0, 0.0))

"""
