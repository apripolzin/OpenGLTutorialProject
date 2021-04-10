cmake_minimum_required(VERSION 3.5)

project(OpenGLTutorialProject LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp display.cpp shader.cpp mesh.cpp texture.cpp obj_loader.cpp)
set(HEADERS display.h shader.h mesh.h texture.h transform.h camera.h obj_loader.h)
set(ASSETS basicShader.vs  basicShader.fs bricks.jpg monkey3.obj)

foreach(asset ${ASSETS})
    add_custom_target(copy_${asset} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/res/${asset})
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/res/${asset}
                       COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/res/${asset}
                                                        ${CMAKE_CURRENT_BINARY_DIR}/res/${asset}
                       DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/res/${asset})
endforeach(asset)

add_library(stb_image STATIC stb_image.h stb_image.c)

add_executable(OpenGLTutorialProject ${SOURCES} ${HEADERS})
target_link_libraries(OpenGLTutorialProject GL GLEW SDL2 stb_image)
