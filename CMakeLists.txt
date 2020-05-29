cmake_minimum_required(VERSION 3.0)
project(OpenCV1)


set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories({OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")

add_subdirectory(ImageOperations)

add_subdirectory(MathOperationsOnImage)
message(STATUS "opencv libs: ${OpenCV_LIBS}")
