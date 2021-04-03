cmake_minimum_required(VERSION 3.5)

project(OpenGLTutorialProject LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp display.cpp shader.cpp mesh.cpp texture.cpp)
set(HEADERS display.h shader.h mesh.h texture.h)
set(SHADERS basicShader.vs  basicShader.fs bricks.jpg)

foreach(shader ${SHADERS})
    add_custom_target(copy_${shader} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/res/${shader})
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/res/${shader}
                       COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/res/${shader}
                                                        ${CMAKE_CURRENT_BINARY_DIR}/res/${shader}
                       DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/res/${shader})
endforeach(asset)

add_library(stb_image STATIC stb_image.h stb_image.c)

add_executable(OpenGLTutorialProject ${SOURCES} ${HEADERS})
target_link_libraries(OpenGLTutorialProject GL GLEW SDL2 stb_image)
