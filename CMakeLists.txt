cmake_minimum_required(VERSION 3.17)
project(normal_linux_programming C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(chap01)

add_executable(normal_linux_programming
        chap01/hello.c chap01/1_5_コマンドライン引数/hello.c chap01/1_5_コマンドライン引数/args.c chap01/1_5_コマンドライン引数/intentional_segmentation_fault.c chap04/bell.c chap05/cat.c chap05/cat2.c chap05/cat3.c chap05/wc_slow.c chap05/wc.c chap05/wc-l-stdio.c)
