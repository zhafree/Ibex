// Generated by gencpp from file ros_vision/SetParameterValueRequest.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_SETPARAMETERVALUEREQUEST_H
#define ROS_VISION_MESSAGE_SETPARAMETERVALUEREQUEST_H


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
struct SetParameterValueRequest_
{
  typedef SetParameterValueRequest_<ContainerAllocator> Type;

  SetParameterValueRequest_()
    : filter_name()
    , parameter_name()
    , parameter_value()
    , update_topics(false)  {
    }
  SetParameterValueRequest_(const ContainerAllocator& _alloc)
    : filter_name(_alloc)
    , parameter_name(_alloc)
    , parameter_value(_alloc)
    , update_topics(false)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _filter_name_type;
  _filter_name_type filter_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _parameter_name_type;
  _parameter_name_type parameter_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _parameter_value_type;
  _parameter_value_type parameter_value;

   typedef uint8_t _update_topics_type;
  _update_topics_type update_topics;




  typedef boost::shared_ptr< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetParameterValueRequest_

typedef ::ros_vision::SetParameterValueRequest_<std::allocator<void> > SetParameterValueRequest;

typedef boost::shared_ptr< ::ros_vision::SetParameterValueRequest > SetParameterValueRequestPtr;
typedef boost::shared_ptr< ::ros_vision::SetParameterValueRequest const> SetParameterValueRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::SetParameterValueRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9dfb3622c3b8f3307e6b9b3b516248ca";
  }

  static const char* value(const ::ros_vision::SetParameterValueRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9dfb3622c3b8f330ULL;
  static const uint64_t static_value2 = 0x7e6b9b3b516248caULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/SetParameterValueRequest";
  }

  static const char* value(const ::ros_vision::SetParameterValueRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string filter_name\n\
string parameter_name\n\
string parameter_value\n\
bool update_topics\n\
";
  }

  static const char* value(const ::ros_vision::SetParameterValueRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.filter_name);
      stream.next(m.parameter_name);
      stream.next(m.parameter_value);
      stream.next(m.update_topics);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SetParameterValueRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::SetParameterValueRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::SetParameterValueRequest_<ContainerAllocator>& v)
  {
    s << indent << "filter_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.filter_name);
    s << indent << "parameter_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.parameter_name);
    s << indent << "parameter_value: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.parameter_value);
    s << indent << "update_topics: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.update_topics);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_SETPARAMETERVALUEREQUEST_H
