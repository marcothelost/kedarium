# Executable
add_executable(
  example
  Example.cpp
)

# GLFW Directory
if(NOT APPLE)
  set(GLFW_INSTALL_DIR ${CMAKE_SOURCE_DIR})
  include_directories(${GLFW_INSTALL_DIR}/include)
  link_directories(${GLFW_INSTALL_DIR}/lib)
endif()

# GLEW Directory
if(NOT APPLE)
  set(GLEW_INSTALL_DIR ${CMAKE_SOURCE_DIR})
  include_directories(${GLEW_INSTALL_DIR}/include)
  link_directories(${GLEW_INSTALL_DIR}/lib)
endif()

# libPNG Directory
if(NOT APPLE)
  set(PNG_INSTALL_DIR ${CMAKE_SOURCE_DIR})
  include_directories(${PNG_INSTALL_DIR}/include)
  link_directories(${PNG_INSTALL_DIR}/lib)
endif()

# Libraries
target_link_libraries(example PRIVATE GLEW glfw png Kedarium)
if(APPLE)
  target_link_libraries(example PRIVATE "-framework OpenGL")
else()
  target_link_libraries(example PRIVATE GL)
endif()

# Include Directory
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Assets Directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
