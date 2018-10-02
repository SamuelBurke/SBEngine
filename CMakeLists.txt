cmake_minimum_required(VERSION 2.6)
project(SBENGINE)

add_executable(test_engine
 src/test_engine/main.cpp
)

add_library(SBEngine
 src/SBEngine/engine.cpp
 src/SBEngine/Core.h
 src/SBEngine/Core.cpp
 src/SBEngine/Entity.h
 src/SBEngine/Entity.cpp
 src/SBEngine/Environment.h
 src/SBEngine/Environment.cpp
)

target_link_libraries(test_engine SBEngine)
