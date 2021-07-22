/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <folly/futures/Future.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp2/async/AsyncClient.h>
#include <thrift/lib/cpp2/async/FutureRequest.h>
#include "./gen-cpp2/example_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace tamvm { namespace cpp2 {

class EchoServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "EchoService";
  }

  virtual void echo(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
  virtual void echo(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 private:
  virtual void echoImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 public:
  virtual void sync_echo( ::tamvm::cpp2::EchoResponse& _return, const  ::tamvm::cpp2::EchoRequest& request);
  virtual void sync_echo(apache::thrift::RpcOptions& rpcOptions,  ::tamvm::cpp2::EchoResponse& _return, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::Future< ::tamvm::cpp2::EchoResponse> future_echo(const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::SemiFuture< ::tamvm::cpp2::EchoResponse> semifuture_echo(const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::Future< ::tamvm::cpp2::EchoResponse> future_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::SemiFuture< ::tamvm::cpp2::EchoResponse> semifuture_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::Future<std::pair< ::tamvm::cpp2::EchoResponse, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::SemiFuture<std::pair< ::tamvm::cpp2::EchoResponse, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual void echo(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::tamvm::cpp2::EchoRequest& request);
  static folly::exception_wrapper recv_wrapped_echo( ::tamvm::cpp2::EchoResponse& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_echo( ::tamvm::cpp2::EchoResponse& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_echo( ::tamvm::cpp2::EchoResponse& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_echo( ::tamvm::cpp2::EchoResponse& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void echoT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 public:
  virtual void oneway_echo(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
  virtual void oneway_echo(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 private:
  virtual void oneway_echoImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 public:
  virtual void sync_oneway_echo(const  ::tamvm::cpp2::EchoRequest& request);
  virtual void sync_oneway_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::Future<folly::Unit> future_oneway_echo(const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_echo(const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::Future<folly::Unit> future_oneway_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_echo(apache::thrift::RpcOptions& rpcOptions, const  ::tamvm::cpp2::EchoRequest& request);
  virtual void oneway_echo(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::tamvm::cpp2::EchoRequest& request);
 private:
  template <typename Protocol_>
  void oneway_echoT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::tamvm::cpp2::EchoRequest& request);
 public:
};

}} // tamvm::cpp2
