cmake_minimum_required(VERSION 3.26)
project(LZV_unlimited)

set(CMAKE_CXX_STANDARD 23)

add_executable(LZV_unlimited main.cpp
        Reader.cpp
        Reader.h
        Writer.cpp
        Writer.h
        encode.cpp
        encode.h
        int_code.h
        int_code.cpp
        decode.cpp
        decode.h)
