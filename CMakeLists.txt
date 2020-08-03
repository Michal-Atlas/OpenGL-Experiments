cmake_minimum_required(VERSION 3.17)
project(MAGE)

set(CMAKE_CXX_STANDARD 14)

add_library(MAGE Shader.cpp Object.cpp Collision.cpp Collision.h Texture.h MAGE.cpp)
target_link_libraries(MAGE glfw OpenGL GLEW)