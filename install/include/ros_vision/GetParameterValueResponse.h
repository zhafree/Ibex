// Generated by gencpp from file ros_vision/GetParameterValueResponse.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_GETPARAMETERVALUERESPONSE_H
#define ROS_VISION_MESSAGE_GETPARAMETERVALUERESPONSE_H


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
struct GetParameterValueResponse_
{
  typedef GetParameterValueResponse_<ContainerAllocator> Type;

  GetParameterValueResponse_()
    : parameter_value()  {
    }
  GetParameterValueResponse_(const ContainerAllocator& _alloc)
    : parameter_value(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _parameter_value_type;
  _parameter_value_type parameter_value;




  typedef boost::shared_ptr< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetParameterValueResponse_

typedef ::ros_vision::GetParameterValueResponse_<std::allocator<void> > GetParameterValueResponse;

typedef boost::shared_ptr< ::ros_vision::GetParameterValueResponse > GetParameterValueResponsePtr;
typedef boost::shared_ptr< ::ros_vision::GetParameterValueResponse const> GetParameterValueResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::GetParameterValueResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6d787a3ade349d12c71db994bbae17bd";
  }

  static const char* value(const ::ros_vision::GetParameterValueResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6d787a3ade349d12ULL;
  static const uint64_t static_value2 = 0xc71db994bbae17bdULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/GetParameterValueResponse";
  }

  static const char* value(const ::ros_vision::GetParameterValueResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string parameter_value\n\
";
  }

  static const char* value(const ::ros_vision::GetParameterValueResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.parameter_value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct GetParameterValueResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::GetParameterValueResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::GetParameterValueResponse_<ContainerAllocator>& v)
  {
    s << indent << "parameter_value: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.parameter_value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_GETPARAMETERVALUERESPONSE_H
