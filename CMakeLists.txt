cmake_minimum_required(VERSION 2.8.0)
project(SOS)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOS_SOURCES
        src/Day.cpp
        src/Dungeon.cpp
        src/Entity.cpp
        src/Item.cpp
        src/Monster.cpp
        src/Player.cpp
        src/Skill.cpp
        src/Usable.cpp)

add_executable(sos_game ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOS_SOURCES})