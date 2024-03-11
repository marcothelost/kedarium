# Executable
add_executable(
  example
  Example.cpp
)

# Libraries
target_link_libraries(example PRIVATE GL GLEW glfw Kedarium)

# Include Directory
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Assets Directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
