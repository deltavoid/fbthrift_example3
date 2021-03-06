/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/GeneratedHeaderHelper.h>
#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/gen/module_types_h.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>


// BEGIN declare_enums

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace tamvm { namespace cpp2 {
class EchoRequest;
class EchoResponse;
}} // tamvm::cpp2
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace tamvm { namespace cpp2 {
class EchoRequest final : private apache::thrift::detail::st::ComparisonOperators<EchoRequest> {
 public:

  EchoRequest() :
      id(0) {}
  // FragileConstructor for use in initialization lists only.
  EchoRequest(apache::thrift::FragileConstructor, int32_t id__arg, std::string message__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    id = arg.extract();
    __isset.id = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    message = arg.extract();
    __isset.message = true;
  }

  EchoRequest(EchoRequest&&) = default;

  EchoRequest(const EchoRequest&) = default;

  EchoRequest& operator=(EchoRequest&&) = default;

  EchoRequest& operator=(const EchoRequest&) = default;
  void __clear();
  int32_t id;
  std::string message;

  struct __isset {
    bool id;
    bool message;
  } __isset = {};
  bool operator==(const EchoRequest& rhs) const;
  bool operator<(const EchoRequest& rhs) const;

  int32_t get_id() const {
    return id;
  }

  int32_t& set_id(int32_t id_) {
    id = id_;
    __isset.id = true;
    return id;
  }

  const std::string& get_message() const& {
    return message;
  }

  std::string get_message() && {
    return std::move(message);
  }

  template <typename T_EchoRequest_message_struct_setter = std::string>
  std::string& set_message(T_EchoRequest_message_struct_setter&& message_) {
    message = std::forward<T_EchoRequest_message_struct_setter>(message_);
    __isset.message = true;
    return message;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< EchoRequest >;
};

void swap(EchoRequest& a, EchoRequest& b);
extern template void EchoRequest::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t EchoRequest::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t EchoRequest::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t EchoRequest::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void EchoRequest::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t EchoRequest::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t EchoRequest::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t EchoRequest::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t EchoRequest::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // tamvm::cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::tamvm::cpp2::EchoRequest>::clear( ::tamvm::cpp2::EchoRequest* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::tamvm::cpp2::EchoRequest>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoRequest>::write(Protocol* proto,  ::tamvm::cpp2::EchoRequest const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::tamvm::cpp2::EchoRequest>::read(Protocol* proto,  ::tamvm::cpp2::EchoRequest* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoRequest>::serializedSize(Protocol const* proto,  ::tamvm::cpp2::EchoRequest const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoRequest>::serializedSizeZC(Protocol const* proto,  ::tamvm::cpp2::EchoRequest const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace tamvm { namespace cpp2 {
class EchoResponse final : private apache::thrift::detail::st::ComparisonOperators<EchoResponse> {
 public:

  EchoResponse() :
      id(0) {}
  // FragileConstructor for use in initialization lists only.
  EchoResponse(apache::thrift::FragileConstructor, int32_t id__arg, std::string message__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    id = arg.extract();
    __isset.id = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    message = arg.extract();
    __isset.message = true;
  }

  EchoResponse(EchoResponse&&) = default;

  EchoResponse(const EchoResponse&) = default;

  EchoResponse& operator=(EchoResponse&&) = default;

  EchoResponse& operator=(const EchoResponse&) = default;
  void __clear();
  int32_t id;
  std::string message;

  struct __isset {
    bool id;
    bool message;
  } __isset = {};
  bool operator==(const EchoResponse& rhs) const;
  bool operator<(const EchoResponse& rhs) const;

  int32_t get_id() const {
    return id;
  }

  int32_t& set_id(int32_t id_) {
    id = id_;
    __isset.id = true;
    return id;
  }

  const std::string& get_message() const& {
    return message;
  }

  std::string get_message() && {
    return std::move(message);
  }

  template <typename T_EchoResponse_message_struct_setter = std::string>
  std::string& set_message(T_EchoResponse_message_struct_setter&& message_) {
    message = std::forward<T_EchoResponse_message_struct_setter>(message_);
    __isset.message = true;
    return message;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< EchoResponse >;
};

void swap(EchoResponse& a, EchoResponse& b);
extern template void EchoResponse::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t EchoResponse::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t EchoResponse::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t EchoResponse::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void EchoResponse::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t EchoResponse::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t EchoResponse::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t EchoResponse::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t EchoResponse::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // tamvm::cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::tamvm::cpp2::EchoResponse>::clear( ::tamvm::cpp2::EchoResponse* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::tamvm::cpp2::EchoResponse>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoResponse>::write(Protocol* proto,  ::tamvm::cpp2::EchoResponse const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::tamvm::cpp2::EchoResponse>::read(Protocol* proto,  ::tamvm::cpp2::EchoResponse* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoResponse>::serializedSize(Protocol const* proto,  ::tamvm::cpp2::EchoResponse const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::tamvm::cpp2::EchoResponse>::serializedSizeZC(Protocol const* proto,  ::tamvm::cpp2::EchoResponse const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
