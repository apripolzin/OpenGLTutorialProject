cmake_minimum_required(VERSION 3.5)

project(OpenGLTutorialProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp display.cpp shader.cpp)
set(HEADERS display.h shader.h)
set(SHADERS basicShader.vs  basicShader.fs)

foreach(shader ${SHADERS})
    add_custom_target(copy_${shader} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/res/${shader})
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/res/${shader}
                       COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/res/${shader}
                                                        ${CMAKE_CURRENT_BINARY_DIR}/res/${shader}
                       DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/res/${shader})
endforeach(asset)

add_executable(OpenGLTutorialProject ${SOURCES} ${HEADERS})
target_link_libraries(OpenGLTutorialProject GL GLEW SDL2)
