cmake_minimum_required(VERSION 3.10)

project(cpp_template)

set(CMAKE_CXX_STANDARD 17)

if (LINUX)
    list(APPEND COMMON_DEPS pthread m)
endif()

add_subdirectory("libs")
#add_subdirectory("apps")
