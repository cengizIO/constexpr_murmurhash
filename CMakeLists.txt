cmake_minimum_required(VERSION 3.2)
project(constexpr_murmur3_hash)

set(EXECUTABLE_NAME murmur3)
set(EXT_PROJECTS_DIR externals)

add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR})
enable_testing(true)

add_executable(${EXECUTABLE_NAME} test.cc constexpr_murmur3.h)
target_link_libraries(${EXECUTABLE_NAME})

set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD_REQUIRED TRUE)
