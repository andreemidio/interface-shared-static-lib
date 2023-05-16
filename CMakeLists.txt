cmake_minimum_required(VERSION 3.16)

project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH ".")
set(CMAKE_BUILD_WITH_INSTALL_RPATH true)


FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Eigen3 REQUIRED NO_MODULE)
FIND_PACKAGE(Iconv REQUIRED)
SET(OpenCV_STATIC ON)

ADD_DEFINITIONS(${EIGEN3_DEFINITIONS})
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})


add_library(staticfoo OBJECT oi.cpp oi.hpp)
target_link_libraries(staticfoo PRIVATE ${OpenCV_LIBS} Iconv::Iconv)
set_property(TARGET staticfoo PROPERTY POSITION_INDEPENDENT_CODE ON)


add_library(sharedfoo SHARED tchau.cpp $<TARGET_OBJECTS:staticfoo> tchau.hpp)
target_link_libraries(sharedfoo PRIVATE ${OpenCV_LIBS} Iconv::Iconv)
set_property(TARGET sharedfoo PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(untitled main.cpp)

target_link_libraries(untitled PRIVATE sharedfoo)
