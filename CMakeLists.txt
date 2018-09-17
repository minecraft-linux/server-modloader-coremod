cmake_minimum_required(VERSION 2.8)
project(CoreMod)

if (CMAKE_VERSION VERSION_LESS 3.0.0)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(ModLoader REQUIRED)

add_library(CoreMod SHARED version_name.cpp log_forwarder.cpp common_hooks.cpp)
target_link_libraries(CoreMod PUBLIC ModLoader)


