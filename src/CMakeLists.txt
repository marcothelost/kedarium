# Library
add_library(
  Kedarium
  Core.cpp
  File.cpp
  Image.cpp
  Graphics.cpp
  Window.cpp
  Space.cpp
  Camera.cpp
  Solids.cpp
  Object.cpp
)

# Include Directory
target_include_directories(Kedarium PUBLIC ${CMAKE_SOURCE_DIR}/include)
