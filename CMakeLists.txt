cmake_minimum_required(VERSION 3.10)

project(cpp_calculate_multiplication_of_2_matrix)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/out/bin)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(lib/helper_function_matrix)
add_subdirectory(lib/multiply_2_matrix)
add_subdirectory(app)
