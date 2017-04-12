cmake_minimum_required(VERSION 2.8.0)
project(SOS)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test)

set(SOS_SOURCES
        src/Entity.cpp
        src/Usable.cpp)

add_executable(sos_game ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOS_SOURCES})