cmake_minimum_required(VERSION 3.6)
project(CoreMod)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(ModLoader REQUIRED)

add_library(CoreMod SHARED version_name.cpp log_forwarder.cpp common_hooks.cpp)
target_link_libraries(CoreMod PUBLIC ModLoader)


