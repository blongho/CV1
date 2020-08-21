cmake_minimum_required(VERSION 3.0)
project(OpenCV1)

set(EXECUTABLE assignment3)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories({OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")

add_executable(${EXECUTABLE} ${SOURCE_FILES} "submission.cpp")
message(STATUS "project source files: ${SOURCE_FILES}")
message(STATUS "opencv libs: ${OpenCV_LIBS}")
TARGET_LINK_LIBRARIES (${EXECUTABLE}  ${OpenCV_LIBS})