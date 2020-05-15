# CMakeList.txt : CMake project for ImagesAsMatrix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.0)
set(EXE_NAME app)
include_directories(headers)
include_directories(src)

file(GLOB SOURCE_FILES "src/*.cpp")
# Add source to this project's executable.
add_executable (${EXE_NAME} ${SOURCE_FILES} "Main.cpp")
TARGET_LINK_LIBRARIES (${EXE_NAME} ${OpenCV_LIBS})


# TODO: Add tests and install targets if needed.
