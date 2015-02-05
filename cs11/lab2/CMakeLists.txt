cmake_minimum_required(VERSION 2.8)

project(VectorTest)

aux_source_directory(. SRCS)

add_executable(VectorTest VectorTest.cc ${SRCS})
target_link_libraries(VectorTest gtest gtest_main pthread)
