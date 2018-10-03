cmake_minimum_required(VERSION 2.6)
project(SBENGINE)

if (MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
endif()

if (MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

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
 src/SBEngine/Keyboard.h
 src/SBEngine/Keyboard.cpp
 src/SBEngine/Component.h
 src/SBEngine/Component.cpp
)

if(MSVC)
  target_link_libraries(test_engine 
    SDL2 glew32 SBEngine
  )
else()
  target_link_libraries(test_engine
    SDL2 GLU GLEW GL SBEngine
  )
endif()

if(MSVC)
  add_custom_command(TARGET test_engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:test_engine>"
  )

  add_custom_command(TARGET test_engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:test_engine>"
  )
endif()














