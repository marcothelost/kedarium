# Executable
add_executable(
  example
  Example.cpp
)

add_executable(
  solar
  Sun.cpp
)

# Libraries
target_link_libraries(example PRIVATE GL GLEW glfw png Kedarium)
target_link_libraries(solar PRIVATE GL GLEW glfw png Kedarium)

# Include Directory
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(solar PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Assets Directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
