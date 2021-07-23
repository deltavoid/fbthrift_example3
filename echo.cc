#include <stdio.h>

#include <vector>

#include <glog/logging.h>

#include <folly/init/Init.h>
#include <folly/portability/GFlags.h>
#include <folly/futures/Future.h>
#include <folly/Unit.h>
#include <folly/synchronization/Baton.h>

#include <thrift/lib/cpp/async/TAsyncSocket.h>
#include <thrift/lib/cpp2/server/ThriftServer.h>
#include <thrift/lib/cpp2/async/HeaderClientChannel.h>

#include "./EchoHandler.h"


using apache::thrift::ThriftServer;
using apache::thrift::ThriftServerAsyncProcessorFactory;
using apache::thrift::RequestCallback;
using apache::thrift::ClientReceiveState;
using apache::thrift::HeaderClientChannel;
using apache::thrift::async::TAsyncSocket;

using tamvm::cpp2::EchoHandler;
using tamvm::cpp2::EchoServiceAsyncClient;
using tamvm::cpp2::EchoRequest;
using tamvm::cpp2::EchoResponse;

constexpr std::int32_t thrift_port = 9000;

TAsyncSocket::UniquePtr getSocket(
    folly::EventBase* evb,
    folly::SocketAddress const& addr,
    std::list<std::string> advertizedProtocols = {}) 
{

  TAsyncSocket::UniquePtr sock(new TAsyncSocket(evb, addr));

  sock->setZeroCopy(true);

  return sock;
}

static std::unique_ptr<EchoServiceAsyncClient> newHeaderClient(
    folly::EventBase* evb,
    folly::SocketAddress const& addr) 
{

  auto sock = getSocket(evb, addr);

  auto chan = HeaderClientChannel::newChannel(std::move(sock));

  chan->setProtocolId(apache::thrift::protocol::T_BINARY_PROTOCOL);

  return std::make_unique<EchoServiceAsyncClient>(std::move(chan));
}


std::unique_ptr<ThriftServer> newServer(int32_t port) 
{

  auto handler = std::make_shared<EchoHandler>();

  auto proc_factory =
      std::make_shared<ThriftServerAsyncProcessorFactory<EchoHandler>>(handler);


  auto server = std::make_unique<ThriftServer>();

  // server->setAddress(addr);
  server->setPort(port);

  server->setProcessorFactory(proc_factory);

  return server;
}

// class AsyncCallback : public apache::thrift::RequestCallback {
//  public:
//  	AsyncCallback(ClientReceiveState* result, folly::Baton<>* baton)
//  		: result_(result), baton_(baton) {}
//  	void requestSent() override {
//  		LOG(INFO) << "client: requestSent";
//  	}

// 	void replyReceived(ClientReceiveState&& state) override {
// 		LOG(INFO) << "client: replyReceived";
// 		*result_ = std::move(state);
// 		baton_->post();
// 	}

// 	void requestError(ClientReceiveState&& state) override {
// 		LOG(ERROR) << "client: requestError";		
// 		*result_ = std::move(state);
// 		LOG(ERROR) << "exception: " << result_->exception();
// 		baton_->post();
// 	}
//   private:
//   	folly::Baton<>* baton_;
//   	ClientReceiveState* result_;
// };
// void onReply(int64_t number) {
// 	LOG(INFO) << "client: get response " << number;
// 	std::this_thread::sleep_for(std::chrono::seconds(1));
// }

void onReply(EchoResponse response) {
	LOG(INFO) << "client: get response, id: " << response.id << " message: " << response.message;

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void onError(std::exception const& e) {
	LOG(ERROR) << "client: error: " << e.what();
}

int main(int argc, char *argv[]) {

	DLOG(INFO) << "main: 1";
	LOG(INFO) << "Starting test ...";
	FLAGS_logtostderr = 1;	
	folly::init(&argc, &argv);
		


	
	// starting server on a separate thread
	DLOG(INFO) << "main: 2";
	std::thread server_thread([] {	    

		DLOG(INFO) << "main: 3";
	    auto server = newServer(thrift_port);
	    
		DLOG(INFO) << "main: 4";
		LOG(INFO) << "server: starts";	    
		server->serve();

		DLOG(INFO) << "main: 5";
	});
	DLOG(INFO) << "main: 6";
	server_thread.detach();

    
	// wait for a short while 
	// enough for socket opening 
	DLOG(INFO) << "main: 7";
	std::this_thread::sleep_for(std::chrono::milliseconds(50));


    
	// create event runloop, to run on this thread
	DLOG(INFO) << "main: 8";
	folly::EventBase eb;
	folly::SocketAddress addr("127.0.0.1", thrift_port);


    DLOG(INFO) << "main: 9";
	// creating client
	auto client = newHeaderClient(&eb, addr);

    DLOG(INFO) << "main: 10";
	std::vector<folly::Future<folly::Unit>> futs;
	for (int32_t i = 10; i < 14; i++) {
	
        DLOG(INFO) << "main: 11";
		LOG(INFO) << "client: send request, id: " << i;
	
		// auto f = client->future_get_number(i);

        EchoRequest request;
		request.id = i;
        request.message = "hello";

		auto f = client->future_echo(request);

	    DLOG(INFO) << "main: 12";
		futs.push_back(
			std::move(f)
			.thenValue(onReply)
			.thenError<std::exception>(onError)
		);

		// std::this_thread::sleep_for(std::chrono::seconds(1));

	}

    DLOG(INFO) << "main: 13";
	collectAll(futs.begin(), futs.end())
	.thenValue( [&eb](std::vector<folly::Try<folly::Unit>>&& v) {

        DLOG(INFO) << "main: 14";
		LOG(INFO) << "client: received all responses";

		eb.terminateLoopSoon();

		DLOG(INFO) << "main: 15";
	});

    DLOG(INFO) << "main: 16";
	// libevent/epoll loop which keeps main thread from existing.
	eb.loopForever();
	

	DLOG(INFO) << "main: 17";
	return 0;
}
