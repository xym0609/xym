cmake_minimum_required(VERSION 3.20)

project(cpp_template VERSION 0.1.0 LANGUAGES CXX)

add_executable(cpp_template
    src/main.cpp
)

target_compile_features(cpp_template PRIVATE cxx_std_20)

set_target_properties(cpp_template PROPERTIES
    CXX_EXTENSIONS OFF
)

if(MSVC)
    target_compile_options(cpp_template PRIVATE /W4 /permissive-)
else()
    target_compile_options(cpp_template PRIVATE -Wall -Wextra -Wpedantic)
endif()