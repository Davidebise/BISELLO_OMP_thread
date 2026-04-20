cmake_minimum_required(VERSION 3.20)
project(BISELLO_OMP_thread)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenMP REQUIRED)

add_executable(BISELLO_OMP_thread main.cpp)
if(OpenMP_CXX_FOUND)
    target_link_libraries(BISELLO_OMP_thread PRIVATE OpenMP::OpenMP_CXX)
    endif()