cmake_minimum_required(VERSION 3.28)
project(untitled3 C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled3 main.c
        libs/file_io/file.c
        libs/file_io/file.h
        libs/file_io/file_test.c
        libs/file_io/file_test.h)

add_subdirectory(libs)

target_link_libraries(untitled3 data_structures)
target_link_libraries(untitled3 algorithms)
target_link_libraries(untitled3 string)
target_link_libraries(untitled3 file_io)