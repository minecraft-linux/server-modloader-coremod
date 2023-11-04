cmake_minimum_required(VERSION 2.8)
project(CoreMod)

if (CMAKE_VERSION VERSION_LESS 3.0.0)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#BDS is linked to libc++ since 1.20.40
if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  message(NOTICE "Setting compiler to clang++")
  set(CMAKE_CXX_COMPILER "clang++")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")

set(MOD_VERSION "v0.0.1-alpha2")

find_package(ModLoader REQUIRED)

add_library(CoreMod SHARED version_name.cpp log_forwarder.cpp common_hooks.cpp)
target_link_libraries(CoreMod PUBLIC ModLoader)


