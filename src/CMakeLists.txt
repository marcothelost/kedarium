# Library
add_library(
  Kedarium
  Core.cpp
)

# Include Directory
target_include_directories(Kedarium PUBLIC ${CMAKE_SOURCE_DIR}/include)
