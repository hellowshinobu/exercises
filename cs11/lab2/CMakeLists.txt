cmake_minimum_required(VERSION 2.8)

project(VectorTest)

aux_source_directory(. SRCS)
include_directories(.)

add_executable(VectorTest VectorTest.cc vector3f.cc)
target_link_libraries(VectorTest gtest gtest_main pthread)

add_executable(ColorTest ColorTest.cc)
target_link_libraries(ColorTest gtest gtest_main pthread)
