#pragma once

#include <glog/logging.h>
#include "./gen-cpp2/ExampleService.h"

namespace tamvm { namespace cpp2 {


class ExampleHandler: public ExampleServiceSvIf {
public:
	int64_t get_number(int32_t n) override {
		LOG(INFO) << "server: receive " << n;
		return n + 10;
	}
};


}} // namespace tamvm::cpp2
