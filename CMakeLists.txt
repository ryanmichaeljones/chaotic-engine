cmake_minimum_required(VERSION 2.6)
project(engine)

include_directories(src
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/include
  ${PROJECT_SOURCE_DIR}/contrib/SDL2/include
  ${PROJECT_SOURCE_DIR}/contrib/stb
  ${PROJECT_SOURCE_DIR}/contrib/OpenAL-soft/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/lib
  ${PROJECT_SOURCE_DIR}/contrib/SDL2/lib
  ${PROJECT_SOURCE_DIR}/contrib/stb
  ${PROJECT_SOURCE_DIR}/contrib/OpenAL-soft/lib
)

add_executable(game
  src/game/main.cpp
  src/game/engine.h
  src/game/Player.cpp
  src/game/Player.h
  src/game/TestScene.cpp
  src/game/TestScene.h
)
  
add_library(engine
  src/engine/Core.cpp
  src/engine/Core.h
  src/engine/Entity.cpp
  src/engine/Entity.h
  src/engine/Component.cpp
  src/engine/Component.h
  src/engine/Renderer.cpp
  src/engine/Renderer.h
  src/engine/Exception.cpp
  src/engine/Exception.h
  src/engine/Transform.cpp
  src/engine/Transform.h
  src/engine/Texture.cpp
  src/engine/Texture.h
  src/engine/Keyboard.cpp
  src/engine/Keyboard.h
  src/engine/Screen.cpp
  src/engine/Screen.h
  src/engine/Sound.cpp
  src/engine/Sound.h
  src/engine/SoundSource.cpp
  src/engine/SoundSource.h
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

target_link_libraries(game 
  SDL2.lib;
  SDL2main.lib;
  opengl32.lib;
  glew32.lib;
  glew32s.lib;
  OpenAL32.lib;
)

target_link_libraries(engine rend ${LIBSDL2} ${STATIC_LIBS})
target_link_libraries(game engine)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

