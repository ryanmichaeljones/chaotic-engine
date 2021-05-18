cmake_minimum_required(VERSION 2.6)
project(CHAOTIC-ENGINE)

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/include
  ${PROJECT_SOURCE_DIR}/contrib/SDL2/include
  ${PROJECT_SOURCE_DIR}/contrib/stb
)

link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/lib
  ${PROJECT_SOURCE_DIR}/contrib/SDL2/lib
  ${PROJECT_SOURCE_DIR}/contrib/stb
)

add_executable(game
  src/game/main.cpp
  src/game/Engine.h
  src/game/Game.cpp
  src/game/Game.h
  src/game/TestScene.cpp
  src/game/TestScene.h
)

add_library(chaotic-engine
  src/chaotic-engine/Core.cpp
  src/chaotic-engine/Core.h
  src/chaotic-engine/Screen.cpp
  src/chaotic-engine/Screen.h
  src/chaotic-engine/Environment.cpp
  src/chaotic-engine/Environment.h
  src/chaotic-engine/Entity.cpp
  src/chaotic-engine/Entity.h
  src/chaotic-engine/Component.cpp
  src/chaotic-engine/Component.h
  src/chaotic-engine/Transform.cpp
  src/chaotic-engine/Transform.h
  src/chaotic-engine/Camera.cpp
  src/chaotic-engine/Camera.h
  src/chaotic-engine/Renderer.cpp
  src/chaotic-engine/Renderer.h
  src/chaotic-engine/Texture.cpp
  src/chaotic-engine/Texture.h
  #src/chaotic-engine/Resource.cpp
  #src/chaotic-engine/Resource.h
  #src/chaotic-engine/ResourceManager.cpp
  #src/chaotic-engine/ResourceManager.h
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
)

target_link_libraries(game chaotic-engine)
target_link_libraries(chaotic-engine rend ${LIBSDL2} ${STATIC_LIBS})