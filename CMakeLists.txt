cmake_minimum_required(VERSION 3.10)

project(RefCountingGC C)

file(GLOB SOME_LIB_SOURCES libs/munit/*.c)
add_library(munit STATIC ${SOME_LIB_SOURCES})

add_executable(refcounting_gc main.c)
target_link_libraries(refcounting_gc munit)
include_directories(libs/munit)

target_link_libraries(refcounting_gc munit)
