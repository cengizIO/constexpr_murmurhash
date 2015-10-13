cmake_minimum_required(VERSION 3.2)
project(constexpr_murmur3_hash)

set(EXT_PROJECTS_DIR externals)
add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR})
enable_testing(true)

add_executable(${CMAKE_PROJECT_NAME} test.cc constexpr_murmur3.h)
target_link_libraries(${CMAKE_PROJECT_NAME})

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED TRUE)
