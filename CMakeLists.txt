cmake_minimum_required(VERSION 3.5)

project(thread-demo-01 LANGUAGES C)

add_library(pthreadpool STATIC pthreadpool.c)

add_executable(thread-test-01 main.c)
target_link_libraries(thread-test-01 pthreadpool pthread)
