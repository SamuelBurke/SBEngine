cmake_minimum_required(VERSION 2.6)
project(SBENGINE)

include_directories(
  src
  contrib
)

if (MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/openal-soft/include
    contrib/msvc-windows-x86/ogg/include
    contrib/msvc-windows-x86/vorbis/include
)

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib
)

endif()

if (MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(test_engine 
 src/test_engine/main.cpp)

add_library(SBEngine
 src/SBEngine/SBEngine.h
 src/SBEngine/Core.h
 src/SBEngine/Entity.h
 src/SBEngine/Shader.h
 src/SBEngine/Environment.h
 src/SBEngine/Keyboard.h
 src/SBEngine/Component.h
 src/SBEngine/Triangle.h
 src/SBEngine/Audio.h

 src/SBEngine/Core.cpp
 src/SBEngine/Entity.cpp
 src/SBEngine/Shader.cpp
 src/SBEngine/Environment.cpp
 src/SBEngine/Keyboard.cpp 
 src/SBEngine/Component.cpp
 src/SBEngine/Triangle.cpp
 src/SBEngine/Audio.cpp
)

if(MSVC)
  target_link_libraries(test_engine 
    SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile SBEngine
  )
else()
  target_link_libraries(test_engine
    SDL2 GLU GLEW GL AL ogg vorbis vorbisfile SBEngine
  )
endif()

target_link_libraries(test_engine SBEngine)

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
  add_custom_command(TARGET test_engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:test_engine>"
  )
endif()














