cmake_minimum_required(VERSION 3.0)
project(OpenCV1)

set(EXECUTABLE bitwiseoperations)

set(CMAKE_CXX_STANDARD 17)

#[[ 
    see https://stackoverflow.com/a/48412977
    Make both debug and release versions
    Then, after configuring with cmake, you can run make debug to make the debug target and run make release to make the release target in the same directory.
]]

ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the debug mode.")

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release mode.")

  
ADD_CUSTOM_TARGET(real_with_debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=RelWithDebInfo ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release with debug info mode.")

find_package(OpenCV REQUIRED)

include_directories({OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")

include_directories(headers)

file(GLOB SOURCE_FILES "src/*.cpp")


add_executable(${EXECUTABLE} ${SOURCE_FILES})
message(STATUS "project source files: ${SOURCE_FILES}")
message(STATUS "opencv libs: ${OpenCV_LIBS}")
TARGET_LINK_LIBRARIES (${EXECUTABLE}  ${OpenCV_LIBS})
