// Generated by gencpp from file seagoatvision_ros/ShowGuiResponse.msg
// DO NOT EDIT!


#ifndef SEAGOATVISION_ROS_MESSAGE_SHOWGUIRESPONSE_H
#define SEAGOATVISION_ROS_MESSAGE_SHOWGUIRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace seagoatvision_ros
{
template <class ContainerAllocator>
struct ShowGuiResponse_
{
  typedef ShowGuiResponse_<ContainerAllocator> Type;

  ShowGuiResponse_()
    : success(false)  {
    }
  ShowGuiResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
    }



   typedef uint8_t _success_type;
  _success_type success;




  typedef boost::shared_ptr< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ShowGuiResponse_

typedef ::seagoatvision_ros::ShowGuiResponse_<std::allocator<void> > ShowGuiResponse;

typedef boost::shared_ptr< ::seagoatvision_ros::ShowGuiResponse > ShowGuiResponsePtr;
typedef boost::shared_ptr< ::seagoatvision_ros::ShowGuiResponse const> ShowGuiResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace seagoatvision_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "seagoatvision_ros/ShowGuiResponse";
  }

  static const char* value(const ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
\n\
";
  }

  static const char* value(const ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ShowGuiResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::seagoatvision_ros::ShowGuiResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SEAGOATVISION_ROS_MESSAGE_SHOWGUIRESPONSE_H