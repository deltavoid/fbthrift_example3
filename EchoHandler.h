#pragma once

#include <glog/logging.h>
#include "./gen-cpp2/EchoService.h"

namespace tamvm { namespace cpp2 {


class EchoHandler : public EchoServiceSvIf {
public:

    void echo( ::tamvm::cpp2::EchoResponse& response, 
            std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override
    {
        DLOG(INFO) << "tamvm::cpp2::EchoHandler::echo: 1";
        LOG(INFO) << "server receive: id: " << request->id << " message: " << request->message;

        response.id = request->id;
        response.message = "world";

        DLOG(INFO) << "tamvm::cpp2::EchoHandler::echo: 2, end";
    }

};


}} // namespace tamvm::cpp2