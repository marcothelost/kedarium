# Executable
add_executable(
  example
  Example.cpp
)

# GLFW Directory
set(GLFW_INSTALL_DIR ${CMAKE_SOURCE_DIR})
include_directories(${GLFW_INSTALL_DIR}/include)
link_directories(${GLFW_INSTALL_DIR}/lib)

# GLEW Directory
set(GLEW_INSTALL_DIR ${CMAKE_SOURCE_DIR})
include_directories(${GLEW_INSTALL_DIR}/include)
link_directories(${GLEW_INSTALL_DIR}/lib)

# libPNG Directory
set(PNG_INSTALL_DIR ${CMAKE_SOURCE_DIR})
include_directories(${PNG_INSTALL_DIR}/include)
link_directories(${PNG_INSTALL_DIR}/lib)

# Libraries
target_link_libraries(example PRIVATE GL GLEW glfw png Kedarium)

# Include Directory
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Assets Directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
