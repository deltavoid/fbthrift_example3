#pragma once

#include <glog/logging.h>
#include "./gen-cpp2/EchoService.h"

namespace tamvm { namespace cpp2 {


class EchoHandler : public EchoServiceSvIf {
public:

    void echo( ::tamvm::cpp2::EchoResponse& response, 
            std::unique_ptr< ::tamvm::cpp2::EchoRequest> request) override
    {
        LOG(INFO) << "server receive: " << request->message;

        response.message = request->message;

    }

};


}} // namespace tamvm::cpp2