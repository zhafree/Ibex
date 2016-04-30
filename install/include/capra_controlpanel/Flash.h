// Generated by gencpp from file capra_controlpanel/Flash.msg
// DO NOT EDIT!


#ifndef CAPRA_CONTROLPANEL_MESSAGE_FLASH_H
#define CAPRA_CONTROLPANEL_MESSAGE_FLASH_H

#include <ros/service_traits.h>


#include <capra_controlpanel/FlashRequest.h>
#include <capra_controlpanel/FlashResponse.h>


namespace capra_controlpanel
{

struct Flash
{

typedef FlashRequest Request;
typedef FlashResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Flash
} // namespace capra_controlpanel


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::capra_controlpanel::Flash > {
  static const char* value()
  {
    return "4581db74aae4efc6534413a8b210908c";
  }

  static const char* value(const ::capra_controlpanel::Flash&) { return value(); }
};

template<>
struct DataType< ::capra_controlpanel::Flash > {
  static const char* value()
  {
    return "capra_controlpanel/Flash";
  }

  static const char* value(const ::capra_controlpanel::Flash&) { return value(); }
};


// service_traits::MD5Sum< ::capra_controlpanel::FlashRequest> should match 
// service_traits::MD5Sum< ::capra_controlpanel::Flash > 
template<>
struct MD5Sum< ::capra_controlpanel::FlashRequest>
{
  static const char* value()
  {
    return MD5Sum< ::capra_controlpanel::Flash >::value();
  }
  static const char* value(const ::capra_controlpanel::FlashRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_controlpanel::FlashRequest> should match 
// service_traits::DataType< ::capra_controlpanel::Flash > 
template<>
struct DataType< ::capra_controlpanel::FlashRequest>
{
  static const char* value()
  {
    return DataType< ::capra_controlpanel::Flash >::value();
  }
  static const char* value(const ::capra_controlpanel::FlashRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::capra_controlpanel::FlashResponse> should match 
// service_traits::MD5Sum< ::capra_controlpanel::Flash > 
template<>
struct MD5Sum< ::capra_controlpanel::FlashResponse>
{
  static const char* value()
  {
    return MD5Sum< ::capra_controlpanel::Flash >::value();
  }
  static const char* value(const ::capra_controlpanel::FlashResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_controlpanel::FlashResponse> should match 
// service_traits::DataType< ::capra_controlpanel::Flash > 
template<>
struct DataType< ::capra_controlpanel::FlashResponse>
{
  static const char* value()
  {
    return DataType< ::capra_controlpanel::Flash >::value();
  }
  static const char* value(const ::capra_controlpanel::FlashResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CAPRA_CONTROLPANEL_MESSAGE_FLASH_H
