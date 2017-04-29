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

set(SOS_ITEMS
        src/items/ItemCoffee.cpp
        src/items/ItemTextbook.cpp)

set(SOS_MONSTERS
        )

set(SOS_SKILLS
        src/skills/SkillDebugger.cpp
        src/skills/SkillHack.cpp
        src/skills/SkillOfficeHours.cpp
        src/skills/SkillPenPlan.cpp)

add_executable(sos_game ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOS_SOURCES} ${SOS_SKILLS})