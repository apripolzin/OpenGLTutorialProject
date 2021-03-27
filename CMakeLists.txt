cmake_minimum_required(VERSION 3.5)

project(OpenGLTutorialProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OpenGLTutorialProject main.cpp display.h display.cpp)
target_link_libraries(OpenGLTutorialProject GL GLEW SDL2)
