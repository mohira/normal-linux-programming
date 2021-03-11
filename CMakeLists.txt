cmake_minimum_required(VERSION 3.17)
project(normal_linux_programming C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(chap01)

add_executable(normal_linux_programming
        chap01/hello.c)
