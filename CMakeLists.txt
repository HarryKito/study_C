# Minimum required version of CMake
cmake_minimum_required(VERSION 3.27)
# Project name
project(study_c)

# Set standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Set include (header files) path
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# Add the include to the compiler's search path
include_directories(${INCLUDE_DIR})

# Executable target named 'study_c' and compile '...cpp'
add_executable(study_c basicIO/main.cpp
        include/include.h)
