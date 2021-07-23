cmake_minimum_required(VERSION 3.0.0)
project(fbthrift_ex CXX)




set(CMAKE_CXX_COMPILER g++)

macro(remove_cxx_flag flag)
    string(REPLACE "${flag}" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
endmacro()

option(USE_O2 "Use -O2 instead of the default -O3" OFF)

set(THREADS_PREFER_PTHREAD_FLAG ON)




find_package(FBThrift REQUIRED)
find_package(Folly REQUIRED)
find_package(Wangle REQUIRED)
find_package(Threads REQUIRED)
find_package(Glog)
find_package(Gflags)



FILE(GLOB FBGEN "./gen-cpp2/*.cpp")


add_executable(fbthrift_echo
    echo.cc	
    ${FBGEN}
)
target_include_directories(fbthrift_echo 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(fbthrift_echo
    PUBLIC
        FBThrift::thriftcpp2
)