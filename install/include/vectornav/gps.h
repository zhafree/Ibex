// Generated by gencpp from file vectornav/gps.msg
// DO NOT EDIT!


#ifndef VECTORNAV_MESSAGE_GPS_H
#define VECTORNAV_MESSAGE_GPS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace vectornav
{
template <class ContainerAllocator>
struct gps_
{
  typedef gps_<ContainerAllocator> Type;

  gps_()
    : header()
    , Time(0.0)
    , Week(0)
    , GpsFix(0)
    , NumSats(0)
    , LLA()
    , NedVel()
    , NedAcc()
    , SpeedAcc(0.0)
    , TimeAcc(0.0)  {
    }
  gps_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , Time(0.0)
    , Week(0)
    , GpsFix(0)
    , NumSats(0)
    , LLA(_alloc)
    , NedVel(_alloc)
    , NedAcc(_alloc)
    , SpeedAcc(0.0)
    , TimeAcc(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _Time_type;
  _Time_type Time;

   typedef uint16_t _Week_type;
  _Week_type Week;

   typedef uint8_t _GpsFix_type;
  _GpsFix_type GpsFix;

   typedef uint8_t _NumSats_type;
  _NumSats_type NumSats;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _LLA_type;
  _LLA_type LLA;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _NedVel_type;
  _NedVel_type NedVel;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _NedAcc_type;
  _NedAcc_type NedAcc;

   typedef float _SpeedAcc_type;
  _SpeedAcc_type SpeedAcc;

   typedef float _TimeAcc_type;
  _TimeAcc_type TimeAcc;


    enum { GPSFIX_NO_FIX = 0u };
     enum { GPSFIX_TIME_ONLY = 1u };
     enum { GPSFIX_2D_FIX = 3u };
     enum { GPSFIX_3D_FIX = 4u };
 

  typedef boost::shared_ptr< ::vectornav::gps_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vectornav::gps_<ContainerAllocator> const> ConstPtr;

}; // struct gps_

typedef ::vectornav::gps_<std::allocator<void> > gps;

typedef boost::shared_ptr< ::vectornav::gps > gpsPtr;
typedef boost::shared_ptr< ::vectornav::gps const> gpsConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vectornav::gps_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vectornav::gps_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vectornav

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'vectornav': ['/home/capra/Ibex/src/vectornav/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vectornav::gps_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vectornav::gps_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vectornav::gps_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vectornav::gps_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vectornav::gps_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vectornav::gps_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vectornav::gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "31fb486026a7554448f3ce4a0e767b5c";
  }

  static const char* value(const ::vectornav::gps_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x31fb486026a75544ULL;
  static const uint64_t static_value2 = 0x48f3ce4a0e767b5cULL;
};

template<class ContainerAllocator>
struct DataType< ::vectornav::gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vectornav/gps";
  }

  static const char* value(const ::vectornav::gps_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vectornav::gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header       header\n\
float64               Time\n\
uint16                Week\n\
uint8                 GpsFix\n\
uint8                 NumSats\n\
geometry_msgs/Vector3 LLA\n\
geometry_msgs/Vector3 NedVel\n\
geometry_msgs/Vector3 NedAcc\n\
float32               SpeedAcc\n\
float32               TimeAcc\n\
\n\
\n\
uint8 GPSFIX_NO_FIX=0\n\
uint8 GPSFIX_TIME_ONLY=1\n\
uint8 GPSFIX_2D_FIX=3\n\
uint8 GPSFIX_3D_FIX=4\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::vectornav::gps_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vectornav::gps_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.Time);
      stream.next(m.Week);
      stream.next(m.GpsFix);
      stream.next(m.NumSats);
      stream.next(m.LLA);
      stream.next(m.NedVel);
      stream.next(m.NedAcc);
      stream.next(m.SpeedAcc);
      stream.next(m.TimeAcc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct gps_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vectornav::gps_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vectornav::gps_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "Time: ";
    Printer<double>::stream(s, indent + "  ", v.Time);
    s << indent << "Week: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.Week);
    s << indent << "GpsFix: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.GpsFix);
    s << indent << "NumSats: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.NumSats);
    s << indent << "LLA: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.LLA);
    s << indent << "NedVel: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.NedVel);
    s << indent << "NedAcc: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.NedAcc);
    s << indent << "SpeedAcc: ";
    Printer<float>::stream(s, indent + "  ", v.SpeedAcc);
    s << indent << "TimeAcc: ";
    Printer<float>::stream(s, indent + "  ", v.TimeAcc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VECTORNAV_MESSAGE_GPS_H
