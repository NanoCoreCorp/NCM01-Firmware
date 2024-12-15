cmake_minimum_required(VERSION 2.8.12)

project(ncm01firmware)

include_directories(firmware/include/)
set(SOURCE_DIR firmware/src/)

set(SOURCE_VECTOR3D_LIB ${SOURCE_DIR}/cpp/vectors/vector3d.cpp)

add_library(vector3d STATIC ${SOURCE_VECTOR3D_LIB})

set(SOURCE_FIRMWARE firmware.cpp)
add_executable(firmware ${SOURCE_FIRMWARE})

target_link_libraries(firmware vector3d)
