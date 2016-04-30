// Generated by gencpp from file capra_msgs/ResetPositionResponse.msg
// DO NOT EDIT!


#ifndef CAPRA_MSGS_MESSAGE_RESETPOSITIONRESPONSE_H
#define CAPRA_MSGS_MESSAGE_RESETPOSITIONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace capra_msgs
{
template <class ContainerAllocator>
struct ResetPositionResponse_
{
  typedef ResetPositionResponse_<ContainerAllocator> Type;

  ResetPositionResponse_()
    {
    }
  ResetPositionResponse_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ResetPositionResponse_

typedef ::capra_msgs::ResetPositionResponse_<std::allocator<void> > ResetPositionResponse;

typedef boost::shared_ptr< ::capra_msgs::ResetPositionResponse > ResetPositionResponsePtr;
typedef boost::shared_ptr< ::capra_msgs::ResetPositionResponse const> ResetPositionResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_msgs::ResetPositionResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'capra_msgs': ['/home/capra/Ibex/src/capra_msgs/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::capra_msgs::ResetPositionResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_msgs/ResetPositionResponse";
  }

  static const char* value(const ::capra_msgs::ResetPositionResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::capra_msgs::ResetPositionResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ResetPositionResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_msgs::ResetPositionResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::capra_msgs::ResetPositionResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_MSGS_MESSAGE_RESETPOSITIONRESPONSE_H
