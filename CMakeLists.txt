cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
project(new_standard)
FILE(GLOB SRC_FILES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SRC_FILES})

