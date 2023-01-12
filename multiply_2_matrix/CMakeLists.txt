cmake_minimum_required(VERSION 3.10)

project(multiply_2_matrix)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(multiply_2_matrix SHARED src/multiply_2_matrix.cpp)

install(TARGETS multiply_2_matrix DESTINATION /usr/lib)
install(FILES include/multiply_2_matrix.h DESTINATION include)
