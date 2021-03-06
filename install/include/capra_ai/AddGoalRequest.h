// Generated by gencpp from file capra_ai/AddGoalRequest.msg
// DO NOT EDIT!


#ifndef CAPRA_AI_MESSAGE_ADDGOALREQUEST_H
#define CAPRA_AI_MESSAGE_ADDGOALREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <capra_ai/GoalWithPriority.h>

namespace capra_ai
{
template <class ContainerAllocator>
struct AddGoalRequest_
{
  typedef AddGoalRequest_<ContainerAllocator> Type;

  AddGoalRequest_()
    : goal_with_priority()
    , add_after_current(false)  {
    }
  AddGoalRequest_(const ContainerAllocator& _alloc)
    : goal_with_priority(_alloc)
    , add_after_current(false)  {
    }



   typedef  ::capra_ai::GoalWithPriority_<ContainerAllocator>  _goal_with_priority_type;
  _goal_with_priority_type goal_with_priority;

   typedef uint8_t _add_after_current_type;
  _add_after_current_type add_after_current;




  typedef boost::shared_ptr< ::capra_ai::AddGoalRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_ai::AddGoalRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AddGoalRequest_

typedef ::capra_ai::AddGoalRequest_<std::allocator<void> > AddGoalRequest;

typedef boost::shared_ptr< ::capra_ai::AddGoalRequest > AddGoalRequestPtr;
typedef boost::shared_ptr< ::capra_ai::AddGoalRequest const> AddGoalRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_ai::AddGoalRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_ai::AddGoalRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_ai

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'capra_msgs': ['/home/capra/Ibex/src/capra_msgs/msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'capra_ai': ['/home/capra/Ibex/src/capra_ai/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_ai::AddGoalRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_ai::AddGoalRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_ai::AddGoalRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c569cd6197e360e2ae24c8b7139a6e14";
  }

  static const char* value(const ::capra_ai::AddGoalRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc569cd6197e360e2ULL;
  static const uint64_t static_value2 = 0xae24c8b7139a6e14ULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_ai/AddGoalRequest";
  }

  static const char* value(const ::capra_ai::AddGoalRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "GoalWithPriority goal_with_priority\n\
bool add_after_current\n\
\n\
================================================================================\n\
MSG: capra_ai/GoalWithPriority\n\
actionlib_msgs/GoalID goal_id\n\
geometry_msgs/Pose pose\n\
uint32 priority\n\
================================================================================\n\
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::capra_ai::AddGoalRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.goal_with_priority);
      stream.next(m.add_after_current);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct AddGoalRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_ai::AddGoalRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capra_ai::AddGoalRequest_<ContainerAllocator>& v)
  {
    s << indent << "goal_with_priority: ";
    s << std::endl;
    Printer< ::capra_ai::GoalWithPriority_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_with_priority);
    s << indent << "add_after_current: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.add_after_current);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_AI_MESSAGE_ADDGOALREQUEST_H
