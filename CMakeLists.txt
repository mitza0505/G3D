cmake_minimum_required(VERSION 3.29)
project(G3D)

set(CMAKE_CXX_STANDARD 20)

add_executable(G3D main.cpp
        openGLWindow.cpp
        openGLWindow.h
        openGLWindow.cpp
        vertexBuffer.cpp
        vertexBuffer.h
        indexBuffer.cpp
        indexBuffer.h
        vertexArray.cpp
        vertexArray.h
        includes.h)

find_package(GLUT REQUIRED)

find_package(GLEW REQUIRED)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
target_link_libraries(G3D ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} GLEW::GLEW)
