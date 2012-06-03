cmake_minimum_required(VERSION 2.6)

project(test-random)

set(BOOST_COMPONENTS )

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall")

add_executable(test-random main.cpp)
