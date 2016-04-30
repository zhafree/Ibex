// Generated by gencpp from file capra_msgs/ModuleToggleRequest.msg
// DO NOT EDIT!


#ifndef CAPRA_MSGS_MESSAGE_MODULETOGGLEREQUEST_H
#define CAPRA_MSGS_MESSAGE_MODULETOGGLEREQUEST_H


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
struct ModuleToggleRequest_
{
  typedef ModuleToggleRequest_<ContainerAllocator> Type;

  ModuleToggleRequest_()
    : Module()
    , on(false)  {
    }
  ModuleToggleRequest_(const ContainerAllocator& _alloc)
    : Module(_alloc)
    , on(false)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _Module_type;
  _Module_type Module;

   typedef uint8_t _on_type;
  _on_type on;




  typedef boost::shared_ptr< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ModuleToggleRequest_

typedef ::capra_msgs::ModuleToggleRequest_<std::allocator<void> > ModuleToggleRequest;

typedef boost::shared_ptr< ::capra_msgs::ModuleToggleRequest > ModuleToggleRequestPtr;
typedef boost::shared_ptr< ::capra_msgs::ModuleToggleRequest const> ModuleToggleRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'capra_msgs': ['/home/capra/Ibex/src/capra_msgs/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5417d091a3ca68989e75b1d90cc8e161";
  }

  static const char* value(const ::capra_msgs::ModuleToggleRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5417d091a3ca6898ULL;
  static const uint64_t static_value2 = 0x9e75b1d90cc8e161ULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_msgs/ModuleToggleRequest";
  }

  static const char* value(const ::capra_msgs::ModuleToggleRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string Module\n\
bool on\n\
";
  }

  static const char* value(const ::capra_msgs::ModuleToggleRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Module);
      stream.next(m.on);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ModuleToggleRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_msgs::ModuleToggleRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capra_msgs::ModuleToggleRequest_<ContainerAllocator>& v)
  {
    s << indent << "Module: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.Module);
    s << indent << "on: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.on);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_MSGS_MESSAGE_MODULETOGGLEREQUEST_H
