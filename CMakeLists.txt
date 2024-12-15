cmake_minimum_required(VERSION 2.8)

project(ncm01firmware)

set(SOURCE_VECTOR3D_LIB firmware/src/cpp/vectors/vector3d.cpp)


add_library(vector3d STATIC ${SOURCE_VECTOR3D_LIB})

include_directories(firmware/include/)

set(SOURCE_FIRMWARE firmware.cpp)
add_executable(firmware ${SOURCE_FIRMWARE})

target_link_libraries(firmware vector3d)
