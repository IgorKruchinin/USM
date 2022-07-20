cmake_minimum_required(VERSION 3.23)
project(USM)

set(CMAKE_CXX_STANDARD 17)

add_executable(USM USM.cpp macro_config.h Object.cpp Object.h Section.cpp Section.h)
