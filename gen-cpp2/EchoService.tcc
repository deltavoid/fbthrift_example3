/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "./gen-cpp2/EchoService.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>

namespace tamvm { namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::tamvm::cpp2::EchoRequest*>> EchoService_echo_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRUCT,  ::tamvm::cpp2::EchoResponse*>> EchoService_echo_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::tamvm::cpp2::EchoRequest*>> EchoService_oneway_echo_pargs;
template <typename ProtocolIn_, typename ProtocolOut_>
void EchoServiceAsyncProcessor::_processInThread_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &EchoServiceAsyncProcessor::process_echo<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void EchoServiceAsyncProcessor::process_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  EchoService_echo_pargs args;
  auto uarg_request = std::make_unique< ::tamvm::cpp2::EchoRequest>();
  args.get<0>().value = uarg_request.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "EchoService.echo", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function echo";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("echo", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        if (req->isStream()) {
          req->sendStreamReply({queue.move(), {}});
        } else {
          req->sendReply(queue.move());
        }
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function echo";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<std::unique_ptr< ::tamvm::cpp2::EchoResponse>>>(std::move(req), std::move(ctxStack), return_echo<ProtocolIn_,ProtocolOut_>, throw_wrapped_echo<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_echo(std::move(callback), std::move(uarg_request));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue EchoServiceAsyncProcessor::return_echo(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::tamvm::cpp2::EchoResponse const& _return) {
  ProtocolOut_ prot;
  EchoService_echo_presult result;
  result.get<0>().value = const_cast< ::tamvm::cpp2::EchoResponse*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("echo", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void EchoServiceAsyncProcessor::throw_wrapped_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew << " in function echo";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("echo", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew << " in oneway function echo";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void EchoServiceAsyncProcessor::_processInThread_oneway_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_NO_RESPONSE, &EchoServiceAsyncProcessor::process_oneway_echo<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void EchoServiceAsyncProcessor::process_oneway_echo(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  EchoService_oneway_echo_pargs args;
  auto uarg_request = std::make_unique< ::tamvm::cpp2::EchoRequest>();
  args.get<0>().value = uarg_request.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "EchoService.oneway_echo", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    LOG(ERROR) << ex.what() << " in function oneway_echo";
    return;
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallbackBase>(std::move(req), std::move(ctxStack), nullptr, eb, tm, ctx);
  ctx->setStartedProcessing();
  iface_->async_tm_oneway_echo(std::move(callback), std::move(uarg_request));
}

}} // tamvm::cpp2
namespace apache { namespace thrift {

}} // apache::thrift