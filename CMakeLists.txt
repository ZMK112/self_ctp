cmake_minimum_required(VERSION 3.22)
project(Ctp_Project)

set(CMAKE_CXX_STANDARD 14)
message(${CMAKE_SOURCE_DIR})
#include_directories(.)
include_directories(include)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_SOURCE_DIR}/inlcude)
target_link_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_SOURCE_DIR}/lib)
