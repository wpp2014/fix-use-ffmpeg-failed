cmake_minimum_required(VERSION 3.22)

project(test-vcpkg-ffmpeg)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FFMPEG REQUIRED)

set(COMPILE_DEFINITIONS
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Release>:NDEBUG>
  __STDC_CONSTANT_MACROS
)

set(TARGET test-vcpkg-ffmpeg)
add_executable(${TARGET} main.cc)
target_include_directories(${TARGET} PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_compile_definitions(${TARGET} PRIVATE ${COMPILE_DEFINITIONS})
target_link_libraries(${TARGET} PRIVATE ${FFMPEG_LIBRARIES})
set_property(TARGET ${TARGET} PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
