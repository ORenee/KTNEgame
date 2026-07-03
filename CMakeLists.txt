# Renee Olds 5721169
cmake_minimum_required(VERSION 3.16.0)
project(bombs
  VERSION 0.0.0
  DESCRIPTION "manual reader for Keep Talking and Nobody Explodes"
  LANGUAGES CXX)

enable_testing()

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(bombs
  Blinken.cpp
  Bomb.cpp
  Knob.cpp
  LevelEndExcep.cpp
  main.cpp
  Maze.cpp
  ModuleEndExcep.cpp
  ModulesInfo.cpp
  Input.cpp
  Wires.cpp
  WordMods.cpp
)
