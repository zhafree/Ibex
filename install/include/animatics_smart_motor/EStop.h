// Generated by gencpp from file animatics_smart_motor/EStop.msg
// DO NOT EDIT!


#ifndef ANIMATICS_SMART_MOTOR_MESSAGE_ESTOP_H
#define ANIMATICS_SMART_MOTOR_MESSAGE_ESTOP_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace animatics_smart_motor
{
template <class ContainerAllocator>
struct EStop_
{
  typedef EStop_<ContainerAllocator> Type;

  EStop_()
    : enabled(false)  {
    }
  EStop_(const ContainerAllocator& _alloc)
    : enabled(false)  {
    }



   typedef uint8_t _enabled_type;
  _enabled_type enabled;




  typedef boost::shared_ptr< ::animatics_smart_motor::EStop_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::animatics_smart_motor::EStop_<ContainerAllocator> const> ConstPtr;

}; // struct EStop_

typedef ::animatics_smart_motor::EStop_<std::allocator<void> > EStop;

typedef boost::shared_ptr< ::animatics_smart_motor::EStop > EStopPtr;
typedef boost::shared_ptr< ::animatics_smart_motor::EStop const> EStopConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::animatics_smart_motor::EStop_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::animatics_smart_motor::EStop_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace animatics_smart_motor

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'animatics_smart_motor': ['/home/capra/Ibex/src/animatics_smart_motor/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::animatics_smart_motor::EStop_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::animatics_smart_motor::EStop_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::animatics_smart_motor::EStop_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::animatics_smart_motor::EStop_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::animatics_smart_motor::EStop_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::animatics_smart_motor::EStop_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::animatics_smart_motor::EStop_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2815464f55ab63684cc1bc38072d0b9b";
  }

  static const char* value(const ::animatics_smart_motor::EStop_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2815464f55ab6368ULL;
  static const uint64_t static_value2 = 0x4cc1bc38072d0b9bULL;
};

template<class ContainerAllocator>
struct DataType< ::animatics_smart_motor::EStop_<ContainerAllocator> >
{
  static const char* value()
  {
    return "animatics_smart_motor/EStop";
  }

  static const char* value(const ::animatics_smart_motor::EStop_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::animatics_smart_motor::EStop_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool enabled\n\
";
  }

  static const char* value(const ::animatics_smart_motor::EStop_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::animatics_smart_motor::EStop_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.enabled);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct EStop_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::animatics_smart_motor::EStop_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::animatics_smart_motor::EStop_<ContainerAllocator>& v)
  {
    s << indent << "enabled: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.enabled);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ANIMATICS_SMART_MOTOR_MESSAGE_ESTOP_H
