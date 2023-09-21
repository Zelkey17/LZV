cmake_minimum_required(VERSION 3.26)
project(LZV_limited)

set(CMAKE_CXX_STANDARD 23)

add_executable(LZV_limited main.cpp decode.cpp decode.h encode.cpp encode.h Reader.h Reader.cpp Writer.h Writer.cpp
        decode.cpp)
