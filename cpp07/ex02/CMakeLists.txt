cmake_minimum_required(VERSION 3.10)

project(Array)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
aux_source_directory(. SRC)

add_executable(array ${SRC})
