// Generated by gencpp from file ros_vision/FilterGroupNames.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_FILTERGROUPNAMES_H
#define ROS_VISION_MESSAGE_FILTERGROUPNAMES_H


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
struct FilterGroupNames_
{
  typedef FilterGroupNames_<ContainerAllocator> Type;

  FilterGroupNames_()
    : names()  {
    }
  FilterGroupNames_(const ContainerAllocator& _alloc)
    : names(_alloc)  {
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  _names_type names;




  typedef boost::shared_ptr< ::ros_vision::FilterGroupNames_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::FilterGroupNames_<ContainerAllocator> const> ConstPtr;

}; // struct FilterGroupNames_

typedef ::ros_vision::FilterGroupNames_<std::allocator<void> > FilterGroupNames;

typedef boost::shared_ptr< ::ros_vision::FilterGroupNames > FilterGroupNamesPtr;
typedef boost::shared_ptr< ::ros_vision::FilterGroupNames const> FilterGroupNamesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::FilterGroupNames_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::FilterGroupNames_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::FilterGroupNames_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::FilterGroupNames_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::FilterGroupNames_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dc7ae3609524b18034e49294a4ce670e";
  }

  static const char* value(const ::ros_vision::FilterGroupNames_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdc7ae3609524b180ULL;
  static const uint64_t static_value2 = 0x34e49294a4ce670eULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/FilterGroupNames";
  }

  static const char* value(const ::ros_vision::FilterGroupNames_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] names\n\
";
  }

  static const char* value(const ::ros_vision::FilterGroupNames_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.names);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct FilterGroupNames_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::FilterGroupNames_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::FilterGroupNames_<ContainerAllocator>& v)
  {
    s << indent << "names[]" << std::endl;
    for (size_t i = 0; i < v.names.size(); ++i)
    {
      s << indent << "  names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.names[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_FILTERGROUPNAMES_H
