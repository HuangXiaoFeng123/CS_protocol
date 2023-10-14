cmake_minimum_required(VERSION 3.0.0)
project(cs_serve VERSION 0.1.0 LANGUAGES C)

set(CMAKE_CXX_COMPILE_FEATURES "gcc")
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(./src SrcFiles)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(cs_serve ${SrcFiles})

