# Executable
add_executable(
  example
  Example.cpp
)

# Libraries
target_link_libraries(example PRIVATE GL GLEW glfw)
