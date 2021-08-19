cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 14)

project(ITKImageRead)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(itk_image_read main.cxx)
target_link_libraries(itk_image_read ${ITK_LIBRARIES})
