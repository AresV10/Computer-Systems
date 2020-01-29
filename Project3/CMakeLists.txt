cmake_minimum_required(VERSION 3.15)
project(comp)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp
        newton.txt
        cmake-build-debug/why.txt
        cmake-build-debug/whyy.txt
        wordfreak.c)
