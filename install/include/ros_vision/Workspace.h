// Generated by gencpp from file ros_vision/Workspace.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_WORKSPACE_H
#define ROS_VISION_MESSAGE_WORKSPACE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_vision/IODescriptor.h>
#include <ros_vision/FilterGroup.h>

namespace ros_vision
{
template <class ContainerAllocator>
struct Workspace_
{
  typedef Workspace_<ContainerAllocator> Type;

  Workspace_()
    : name()
    , input_topics()
    , filter_groups()  {
    }
  Workspace_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , input_topics(_alloc)
    , filter_groups(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef std::vector< ::ros_vision::IODescriptor_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ros_vision::IODescriptor_<ContainerAllocator> >::other >  _input_topics_type;
  _input_topics_type input_topics;

   typedef std::vector< ::ros_vision::FilterGroup_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ros_vision::FilterGroup_<ContainerAllocator> >::other >  _filter_groups_type;
  _filter_groups_type filter_groups;




  typedef boost::shared_ptr< ::ros_vision::Workspace_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::Workspace_<ContainerAllocator> const> ConstPtr;

}; // struct Workspace_

typedef ::ros_vision::Workspace_<std::allocator<void> > Workspace;

typedef boost::shared_ptr< ::ros_vision::Workspace > WorkspacePtr;
typedef boost::shared_ptr< ::ros_vision::Workspace const> WorkspaceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::Workspace_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::Workspace_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ros_vision::Workspace_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::Workspace_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::Workspace_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::Workspace_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::Workspace_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::Workspace_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::Workspace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ba66aee9ea0e6ca468c0e52fb7dc685e";
  }

  static const char* value(const ::ros_vision::Workspace_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xba66aee9ea0e6ca4ULL;
  static const uint64_t static_value2 = 0x68c0e52fb7dc685eULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::Workspace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/Workspace";
  }

  static const char* value(const ::ros_vision::Workspace_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::Workspace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
IODescriptor[] input_topics\n\
FilterGroup[] filter_groups\n\
\n\
================================================================================\n\
MSG: ros_vision/IODescriptor\n\
string name\n\
string topic\n\
string type\n\
================================================================================\n\
MSG: ros_vision/FilterGroup\n\
string name\n\
Filter[] filters\n\
================================================================================\n\
MSG: ros_vision/Filter\n\
string name\n\
string type\n\
string description\n\
IODescriptor[] inputs\n\
IODescriptor[] outputs\n\
Parameter[] parameters\n\
\n\
================================================================================\n\
MSG: ros_vision/Parameter\n\
string name\n\
string description\n\
string type\n\
string default\n\
string min\n\
string max\n\
";
  }

  static const char* value(const ::ros_vision::Workspace_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::Workspace_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.input_topics);
      stream.next(m.filter_groups);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Workspace_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::Workspace_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::Workspace_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "input_topics[]" << std::endl;
    for (size_t i = 0; i < v.input_topics.size(); ++i)
    {
      s << indent << "  input_topics[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_vision::IODescriptor_<ContainerAllocator> >::stream(s, indent + "    ", v.input_topics[i]);
    }
    s << indent << "filter_groups[]" << std::endl;
    for (size_t i = 0; i < v.filter_groups.size(); ++i)
    {
      s << indent << "  filter_groups[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_vision::FilterGroup_<ContainerAllocator> >::stream(s, indent + "    ", v.filter_groups[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_WORKSPACE_H
