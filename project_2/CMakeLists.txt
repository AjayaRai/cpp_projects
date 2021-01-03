cmake_minimum_required(VERSION 3.17)
project(testProject2)

set(CMAKE_CXX_STANDARD 14)

add_executable(testProject2 main.cpp FirstDerivedClass.cpp FirstDerivedClass.h ReadFilteredWords.cpp ReadFilteredWords.h ReadWords.cpp ReadWords.h SecondDerivedClass.cpp SecondDerivedClass.h ThirdDerivedClass.cpp ThirdDerivedClass.h)