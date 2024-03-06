#include "Kedarium/Core.hpp"

void kdr::Core::printEngineInfo()
{
  std::cout << kdr::Constants::ENGINE_NAME << " " << kdr::Constants::ENGINE_VERSION << '\n';
  std::cout << "Created by " << kdr::Constants::ENGINE_AUTHOR << '\n';
  std::cout << "Licensed under " << kdr::Constants::ENGINE_LICENSE << '\n';
}

void kdr::Core::printVersionInfo()
{
  std::cout << "OpenGL: " << glGetString(GL_VERSION) << '\n';
  std::cout << "GLEW:   " << glewGetString(GLEW_VERSION) << '\n';
  std::cout << "GLFW:   " << glfwGetVersionString() << '\n';
}
