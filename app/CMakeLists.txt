cmake_minimum_required(VERSION 3.10)

project(app)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(app
    main.cpp
)
target_link_libraries(app multiply_2_matrix helper_function_matrix)