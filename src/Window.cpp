#include "Kedarium/Window.hpp"

void kdr::Window::loop()
{
  while (!glfwWindowShouldClose(this->glfwWindow))
  {
    this->_update();
    this->_render();
  }
}

bool kdr::Window::_initialize()
{
  this->glfwWindow = glfwCreateWindow(
    this->width,
    this->height,
    this->title.c_str(),
    NULL,
    NULL
  );
  if (this->glfwWindow == NULL)
  {
    std::cerr << "Failed to create a GLFW window\n";
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(this->glfwWindow);
  if (!kdr::Core::initializeGlew()) return false;
  return true;
}

void kdr::Window::_update()
{
  glfwPollEvents();
  this->update();
}

void kdr::Window::_render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  this->render();
  glfwSwapBuffers(this->glfwWindow);
}