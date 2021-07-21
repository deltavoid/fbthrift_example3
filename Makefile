


BUILD_DIR:=_build

.PHONY: build run
default: run


build: $(BUILD_DIR)/Makefile
	cd $(BUILD_DIR) && make

$(BUILD_DIR)/Makefile:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && cmake ..

build_thrift:
	thrift1 --gen mstch_cpp2 -o ./ --templates /repos/fbthrift/thrift/compiler/generate/templates  ./example.thrift


run: build
	$(BUILD_DIR)/fbthrift_ex

clean:	
	rm -rf $(BUILD_DIR)
