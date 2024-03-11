# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "kedarium")
set(OpenGL_GL_PREFERENCE "LEGACY")

# Project Name
project(${PROJECT_NAME})

# CXX Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
if(APPLE)
  set(CMAKE_CXX_FLAGS "-std=c++17 -stdlib=libc++ -Wall -Wextra -Wpedantic")
endif()

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(PNG REQUIRED)

# Subdirectories
add_subdirectory(src)
add_subdirectory(examples)
