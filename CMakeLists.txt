cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-std=c99")

project(opengl_test)

find_package(OpenGL REQUIRED)
include_directories(include ${OpenGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)

add_executable(opengl_test apps/main.cc
    /usr/local/include/glad/glad.c
)

target_link_libraries(opengl_test
    ${OPENGL_LIBRARY}
    glfw dl
)

add_executable(cubes apps/cubes.cc
    /usr/local/include/glad/glad.c
)

target_link_libraries(cubes
    ${OPENGL_LIBRARY}
    glfw dl
)
