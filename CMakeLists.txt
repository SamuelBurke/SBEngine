cmake_minimum_required(VERSION 2.6)
project(SBENGINE)

add_executable(test_engine
 src/test_engine/main.cpp
)

add_library(SBEngine
 src/SBEngine/engine.cpp
)

target_link_libraries(test_engine SBEngine)
