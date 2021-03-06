// Generated by gencpp from file capra_msgs/SetWheelSpeed.msg
// DO NOT EDIT!


#ifndef CAPRA_MSGS_MESSAGE_SETWHEELSPEED_H
#define CAPRA_MSGS_MESSAGE_SETWHEELSPEED_H

#include <ros/service_traits.h>


#include <capra_msgs/SetWheelSpeedRequest.h>
#include <capra_msgs/SetWheelSpeedResponse.h>


namespace capra_msgs
{

struct SetWheelSpeed
{

typedef SetWheelSpeedRequest Request;
typedef SetWheelSpeedResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetWheelSpeed
} // namespace capra_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::capra_msgs::SetWheelSpeed > {
  static const char* value()
  {
    return "812356feddcdc2f447f0699a2c1e2105";
  }

  static const char* value(const ::capra_msgs::SetWheelSpeed&) { return value(); }
};

template<>
struct DataType< ::capra_msgs::SetWheelSpeed > {
  static const char* value()
  {
    return "capra_msgs/SetWheelSpeed";
  }

  static const char* value(const ::capra_msgs::SetWheelSpeed&) { return value(); }
};


// service_traits::MD5Sum< ::capra_msgs::SetWheelSpeedRequest> should match 
// service_traits::MD5Sum< ::capra_msgs::SetWheelSpeed > 
template<>
struct MD5Sum< ::capra_msgs::SetWheelSpeedRequest>
{
  static const char* value()
  {
    return MD5Sum< ::capra_msgs::SetWheelSpeed >::value();
  }
  static const char* value(const ::capra_msgs::SetWheelSpeedRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_msgs::SetWheelSpeedRequest> should match 
// service_traits::DataType< ::capra_msgs::SetWheelSpeed > 
template<>
struct DataType< ::capra_msgs::SetWheelSpeedRequest>
{
  static const char* value()
  {
    return DataType< ::capra_msgs::SetWheelSpeed >::value();
  }
  static const char* value(const ::capra_msgs::SetWheelSpeedRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::capra_msgs::SetWheelSpeedResponse> should match 
// service_traits::MD5Sum< ::capra_msgs::SetWheelSpeed > 
template<>
struct MD5Sum< ::capra_msgs::SetWheelSpeedResponse>
{
  static const char* value()
  {
    return MD5Sum< ::capra_msgs::SetWheelSpeed >::value();
  }
  static const char* value(const ::capra_msgs::SetWheelSpeedResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_msgs::SetWheelSpeedResponse> should match 
// service_traits::DataType< ::capra_msgs::SetWheelSpeed > 
template<>
struct DataType< ::capra_msgs::SetWheelSpeedResponse>
{
  static const char* value()
  {
    return DataType< ::capra_msgs::SetWheelSpeed >::value();
  }
  static const char* value(const ::capra_msgs::SetWheelSpeedResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CAPRA_MSGS_MESSAGE_SETWHEELSPEED_H
