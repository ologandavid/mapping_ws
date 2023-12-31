// Generated by gencpp from file ouster_ros/PacketMsg.msg
// DO NOT EDIT!


#ifndef OUSTER_ROS_MESSAGE_PACKETMSG_H
#define OUSTER_ROS_MESSAGE_PACKETMSG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ouster_ros
{
template <class ContainerAllocator>
struct PacketMsg_
{
  typedef PacketMsg_<ContainerAllocator> Type;

  PacketMsg_()
    : buf()  {
    }
  PacketMsg_(const ContainerAllocator& _alloc)
    : buf(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _buf_type;
  _buf_type buf;





  typedef boost::shared_ptr< ::ouster_ros::PacketMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ouster_ros::PacketMsg_<ContainerAllocator> const> ConstPtr;

}; // struct PacketMsg_

typedef ::ouster_ros::PacketMsg_<std::allocator<void> > PacketMsg;

typedef boost::shared_ptr< ::ouster_ros::PacketMsg > PacketMsgPtr;
typedef boost::shared_ptr< ::ouster_ros::PacketMsg const> PacketMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ouster_ros::PacketMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ouster_ros::PacketMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ouster_ros::PacketMsg_<ContainerAllocator1> & lhs, const ::ouster_ros::PacketMsg_<ContainerAllocator2> & rhs)
{
  return lhs.buf == rhs.buf;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ouster_ros::PacketMsg_<ContainerAllocator1> & lhs, const ::ouster_ros::PacketMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ouster_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ouster_ros::PacketMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ouster_ros::PacketMsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ouster_ros::PacketMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ouster_ros::PacketMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ouster_ros::PacketMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ouster_ros::PacketMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ouster_ros::PacketMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4f7b5949e76f86d01e96b0e33ba9b5e3";
  }

  static const char* value(const ::ouster_ros::PacketMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4f7b5949e76f86d0ULL;
  static const uint64_t static_value2 = 0x1e96b0e33ba9b5e3ULL;
};

template<class ContainerAllocator>
struct DataType< ::ouster_ros::PacketMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ouster_ros/PacketMsg";
  }

  static const char* value(const ::ouster_ros::PacketMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ouster_ros::PacketMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8[] buf\n"
;
  }

  static const char* value(const ::ouster_ros::PacketMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ouster_ros::PacketMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.buf);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PacketMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ouster_ros::PacketMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ouster_ros::PacketMsg_<ContainerAllocator>& v)
  {
    s << indent << "buf[]" << std::endl;
    for (size_t i = 0; i < v.buf.size(); ++i)
    {
      s << indent << "  buf[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.buf[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // OUSTER_ROS_MESSAGE_PACKETMSG_H
