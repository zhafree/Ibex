// Generated by gencpp from file ros_vision/StartSignal.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_STARTSIGNAL_H
#define ROS_VISION_MESSAGE_STARTSIGNAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_vision
{
template <class ContainerAllocator>
struct StartSignal_
{
  typedef StartSignal_<ContainerAllocator> Type;

  StartSignal_()
    : group_names()
    , input_time()  {
    }
  StartSignal_(const ContainerAllocator& _alloc)
    : group_names(_alloc)
    , input_time()  {
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _group_names_type;
  _group_names_type group_names;

   typedef ros::Time _input_time_type;
  _input_time_type input_time;




  typedef boost::shared_ptr< ::ros_vision::StartSignal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::StartSignal_<ContainerAllocator> const> ConstPtr;

}; // struct StartSignal_

typedef ::ros_vision::StartSignal_<std::allocator<void> > StartSignal;

typedef boost::shared_ptr< ::ros_vision::StartSignal > StartSignalPtr;
typedef boost::shared_ptr< ::ros_vision::StartSignal const> StartSignalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::StartSignal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::StartSignal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_vision

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'ros_vision': ['/home/capra/Ibex/src/ros_vision/msg', '/home/capra/Ibex/src/ros_vision/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::StartSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::StartSignal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::StartSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::StartSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::StartSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::StartSignal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::StartSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bc31190eab6d5b529f09c9c5a9c6058e";
  }

  static const char* value(const ::ros_vision::StartSignal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbc31190eab6d5b52ULL;
  static const uint64_t static_value2 = 0x9f09c9c5a9c6058eULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::StartSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/StartSignal";
  }

  static const char* value(const ::ros_vision::StartSignal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::StartSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] group_names\n\
time input_time\n\
";
  }

  static const char* value(const ::ros_vision::StartSignal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::StartSignal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.group_names);
      stream.next(m.input_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct StartSignal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::StartSignal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::StartSignal_<ContainerAllocator>& v)
  {
    s << indent << "group_names[]" << std::endl;
    for (size_t i = 0; i < v.group_names.size(); ++i)
    {
      s << indent << "  group_names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.group_names[i]);
    }
    s << indent << "input_time: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.input_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_STARTSIGNAL_H
