cmake_minimum_required(VERSION 3.10)

project(bureaucrat4)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 98)
aux_source_directory(. SRC)
add_executable(bureaucrat4 ${SRC})
