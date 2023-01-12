cmake_minimum_required(VERSION 3.1...3.15)

set(targets "main")

set(proj_name "modules")
set(ver "0.1")

set(lang "CXX")
set(lang_ver "17")

project(${proj_name} VERSION ${ver} LANGUAGES ${lang})

add_executable(${targets} ${targets}.cpp)

target_compile_features(${targets} PUBLIC cxx_std_${lang_ver})
set_target_properties(${targets} PROPERTIES CXX_EXTENSIONS OFF)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${targets} PRIVATE fmt::fmt fmt::fmt-header-only)