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

bool kdr::Core::initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, 4);

  return true;
}

bool kdr::Core::initializeGlew()
{
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cerr << "Failed to initialize GLEW!\n";
    std::cerr << "Error: " << glewGetErrorString(err) << "\n";
    return false;
  }
  return true;
}

void kdr::Core::terminate()
{
  glfwTerminate();
}
