# Minimum required version of CMake
cmake_minimum_required(VERSION 3.2)
# Project name
project(study_c)

# Set standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Setup build type, You can choose [ Debug, Release, RelWithDebInfo, MinSizeRel ]
set(CMAKE_BUILD_TYPE Debug)

# Set output to the specific directory, named /output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Set include (header files) path
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# Add the include to the compiler's search path
include_directories(${INCLUDE_DIR})

# Executable target named 'study_c' and compile '...cpp'
add_executable(study_c basicIO/main.cpp
        include/include.h)
