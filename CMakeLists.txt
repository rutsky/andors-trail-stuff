cmake_minimum_required(VERSION 2.6)

project(test-random)

set(BOOST_COMPONENTS python)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall")

add_executable(test-random main.cpp)

add_library(javarandom SHARED javarandom_python.cpp)
target_link_libraries(javarandom ${Boost_LIBRARIES})
set_target_properties(javarandom PROPERTIES PREFIX "")
