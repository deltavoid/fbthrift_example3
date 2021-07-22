/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <folly/futures/Future.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp2/ServiceIncludes.h>
#include <thrift/lib/cpp2/async/FutureRequest.h>
#include <thrift/lib/cpp2/async/HeaderChannel.h>
#include "./gen-cpp2/EchoServiceAsyncClient.h"
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

class EchoServiceSvAsyncIf {
 public:
  virtual ~EchoServiceSvAsyncIf() {}
  virtual void async_tm_echo(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::tamvm::cpp2::EchoResponse>>> callback, std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) = 0;
  virtual folly::Future<std::unique_ptr< ::tamvm::cpp2::EchoResponse>> future_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) = 0;
  virtual void async_tm_oneway_echo(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) = 0;
  virtual folly::Future<folly::Unit> future_oneway_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) = 0;
};

class EchoServiceAsyncProcessor;

class EchoServiceSvIf : public EchoServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef EchoServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;

  virtual void echo( ::tamvm::cpp2::EchoResponse& /*_return*/, std::unique_ptr< ::tamvm::cpp2::EchoRequest> /*request*/);

  folly::Future<std::unique_ptr< ::tamvm::cpp2::EchoResponse>> future_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override;

  void async_tm_echo(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::tamvm::cpp2::EchoResponse>>> callback, std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override;

  virtual void oneway_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> /*request*/);
  folly::Future<folly::Unit> future_oneway_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override;
  void async_tm_oneway_echo(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override;

};

class EchoServiceSvNull : public EchoServiceSvIf {
 public:
  void echo( ::tamvm::cpp2::EchoResponse& /*_return*/, std::unique_ptr< ::tamvm::cpp2::EchoRequest> /*request*/) override;
  void oneway_echo(std::unique_ptr< ::tamvm::cpp2::EchoRequest> /*request*/) override;
};

class EchoServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  using BaseAsyncProcessor = void;
  using HasFrozen2 = std::false_type;
 protected:
  EchoServiceSvIf* iface_;
  folly::Optional<std::string> getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) override;
 public:
  void process(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  bool isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) override;
 private:
  static std::unordered_set<std::string> onewayMethods_;
  static std::unordered_map<std::string, int16_t> cacheKeyMap_;
 public:
  using BinaryProtocolProcessFunc = ProcessFunc<EchoServiceAsyncProcessor, apache::thrift::BinaryProtocolReader>;
  using BinaryProtocolProcessMap = ProcessMap<BinaryProtocolProcessFunc>;
  static const EchoServiceAsyncProcessor::BinaryProtocolProcessMap& getBinaryProtocolProcessMap();
 private:
  static const EchoServiceAsyncProcessor::BinaryProtocolProcessMap binaryProcessMap_;
 public:
  using CompactProtocolProcessFunc = ProcessFunc<EchoServiceAsyncProcessor, apache::thrift::CompactProtocolReader>;
  using CompactProtocolProcessMap = ProcessMap<CompactProtocolProcessFunc>;
  static const EchoServiceAsyncProcessor::CompactProtocolProcessMap& getCompactProtocolProcessMap();
 private:
  static const EchoServiceAsyncProcessor::CompactProtocolProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_echo(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::tamvm::cpp2::EchoResponse const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_oneway_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_oneway_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
 public:
  EchoServiceAsyncProcessor(EchoServiceSvIf* iface) :
      iface_(iface) {}

  virtual ~EchoServiceAsyncProcessor() {}
};

}} // tamvm::cpp2
namespace apache { namespace thrift {

}} // apache::thrift