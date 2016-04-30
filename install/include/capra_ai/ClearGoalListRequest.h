// Generated by gencpp from file capra_ai/ClearGoalListRequest.msg
// DO NOT EDIT!


#ifndef CAPRA_AI_MESSAGE_CLEARGOALLISTREQUEST_H
#define CAPRA_AI_MESSAGE_CLEARGOALLISTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace capra_ai
{
template <class ContainerAllocator>
struct ClearGoalListRequest_
{
  typedef ClearGoalListRequest_<ContainerAllocator> Type;

  ClearGoalListRequest_()
    : data(false)  {
    }
  ClearGoalListRequest_(const ContainerAllocator& _alloc)
    : data(false)  {
    }



   typedef uint8_t _data_type;
  _data_type data;




  typedef boost::shared_ptr< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ClearGoalListRequest_

typedef ::capra_ai::ClearGoalListRequest_<std::allocator<void> > ClearGoalListRequest;

typedef boost::shared_ptr< ::capra_ai::ClearGoalListRequest > ClearGoalListRequestPtr;
typedef boost::shared_ptr< ::capra_ai::ClearGoalListRequest const> ClearGoalListRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_ai::ClearGoalListRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_ai

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'capra_msgs': ['/home/capra/Ibex/src/capra_msgs/msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'capra_ai': ['/home/capra/Ibex/src/capra_ai/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8b94c1b53db61fb6aed406028ad6332a";
  }

  static const char* value(const ::capra_ai::ClearGoalListRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8b94c1b53db61fb6ULL;
  static const uint64_t static_value2 = 0xaed406028ad6332aULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_ai/ClearGoalListRequest";
  }

  static const char* value(const ::capra_ai::ClearGoalListRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool data\n\
";
  }

  static const char* value(const ::capra_ai::ClearGoalListRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ClearGoalListRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_ai::ClearGoalListRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capra_ai::ClearGoalListRequest_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_AI_MESSAGE_CLEARGOALLISTREQUEST_H
