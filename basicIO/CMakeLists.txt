cmake_minimum_required(VERSION 3.5)
project(basicIO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(basicIO
    main.cpp
    ../include/include.h
)

target_include_directories(basicIO PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")
