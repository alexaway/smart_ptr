cmake_minimum_required(VERSION 3.7)
project(smart_ptr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp smart_ptr.h shared_ptr.h)
add_executable(smart_ptr ${SOURCE_FILES})