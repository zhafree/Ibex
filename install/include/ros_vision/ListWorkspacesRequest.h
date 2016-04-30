// Generated by gencpp from file ros_vision/ListWorkspacesRequest.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_LISTWORKSPACESREQUEST_H
#define ROS_VISION_MESSAGE_LISTWORKSPACESREQUEST_H


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
struct ListWorkspacesRequest_
{
  typedef ListWorkspacesRequest_<ContainerAllocator> Type;

  ListWorkspacesRequest_()
    {
    }
  ListWorkspacesRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ListWorkspacesRequest_

typedef ::ros_vision::ListWorkspacesRequest_<std::allocator<void> > ListWorkspacesRequest;

typedef boost::shared_ptr< ::ros_vision::ListWorkspacesRequest > ListWorkspacesRequestPtr;
typedef boost::shared_ptr< ::ros_vision::ListWorkspacesRequest const> ListWorkspacesRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_vision

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'ros_vision': ['/home/capra/Ibex/src/ros_vision/msg', '/home/capra/Ibex/src/ros_vision/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::ros_vision::ListWorkspacesRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/ListWorkspacesRequest";
  }

  static const char* value(const ::ros_vision::ListWorkspacesRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::ros_vision::ListWorkspacesRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ListWorkspacesRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::ListWorkspacesRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::ros_vision::ListWorkspacesRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_LISTWORKSPACESREQUEST_H
