


BUILD_DIR:=_build

.PHONY: build run
default: run_echo


build: $(BUILD_DIR)/Makefile
	cd $(BUILD_DIR) && make

$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR)  \
	&& cmake -S . -B $(BUILD_DIR) \
	    -DCMAKE_MODULE_PATH=cmake

build_thrift:
	thrift1 --gen mstch_cpp2 -o ./ --templates /repos/fbthrift/thrift/compiler/generate/templates  ./example.thrift


run_echo: build
	$(BUILD_DIR)/fbthrift_echo

run_echo_gdb: build	
	gdb $(BUILD_DIR)/fbthrift_echo

run_server: build
	$(BUILD_DIR)/fbthrift_server

run_client: build
	$(BUILD_DIR)/fbthrift_client

run_client_gdb: build
	gdb $(BUILD_DIR)/fbthrift_client



clean:	
	rm -rf $(BUILD_DIR)
