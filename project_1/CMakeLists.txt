# cmake_minimum_required(VERSION <specify CMake version here>)
project(testProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(testProject main.cpp Person.cpp Person.h Student.cpp Student.h)