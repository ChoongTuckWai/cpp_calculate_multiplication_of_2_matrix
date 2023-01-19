cmake_minimum_required(VERSION 3.10)

project(cpp_calculate_multiplication_of_2_matrix)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(lib/helper_function_matrix)
add_subdirectory(lib/multiply_2_matrix)
add_subdirectory(app)
