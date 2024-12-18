cmake_minimum_required(VERSION 3.5)
project(CmdEngine)

set(EXECUTABLE_TEST "test")
set(EXECUTABLE_ENGINE "Cmd_Engine")
set(EXECUTABLE "${EXECUTABLE_TEST}")
set(MAIN_FILE src/test.cpp)

option(BUILD_ENGINE "Whether to build test or engine executable" OFF)

if (BUILD_ENGINE)
  set(EXECUTABLE "${EXECUTABLE_ENGINE}")
  set(MAIN_FILE src/engine.cpp)
endif()

add_executable(${EXECUTABLE} 
  ${MAIN_FILE}
  src/CmdEngine/cmdengine.h 
  src/CmdEngine/cmdengine.cpp 
  src/CmdEngine/raylib.h 
  src/CmdEngine/raymath.h 
  src/CmdEngine/rlgl.h
  src/CmdEngine/cephysics.h
  src/CmdEngine/cephysics.cpp
  src/CmdEngine/extras.h
  src/CmdEngine/extras.cpp)

target_link_libraries(${EXECUTABLE} raylib)