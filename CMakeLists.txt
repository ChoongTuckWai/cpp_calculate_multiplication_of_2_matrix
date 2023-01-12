cmake_minimum_required(VERSION 3.10)

project(multiply_2_matrix)
set(CMAKE_CXX_STANDARD 11)

# add_library(multiply_2_matrix SHARED multiply_2_matrix.cpp multiply_2_matrix.h)

add_executable(multiply_2_matrix
    main.cpp
    helper_function_matrix.cpp
    helper_function_matrix.h multiply_2_matrix.cpp multiply_2_matrix.h)

