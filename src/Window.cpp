#include "Kedarium/Window.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  (void)window;
  glViewport(0, 0, width, height);
}

void kdr::Window::loop()
{
  while (!glfwWindowShouldClose(this->glfwWindow))
  {
    this->_update();
    this->_render();
  }
}

bool kdr::Window::_initializeWindow()
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
  glfwSetFramebufferSizeCallback(this->glfwWindow, framebufferSizeCallback);
  glClearColor(
    this->clearColor.red,
    this->clearColor.green,
    this->clearColor.blue,
    this->clearColor.alpha
  );
  return true;
}

bool kdr::Window::_initializeOpenGLSettings()
{
  glPointSize(5.f);
  glLineWidth(2.f);

  return true;
}

bool kdr::Window::_initialize()
{
  if (!this->_initializeWindow()) return false;
  if (!kdr::Core::initializeGlew()) return false;
  if (!this->_initializeOpenGLSettings()) return false;

  return true;
}

void kdr::Window::_updateDeltaTime()
{
  float currentTime = (float)glfwGetTime();
  this->deltaTime = currentTime - lastTime;
  this->lastTime = currentTime;
}

void kdr::Window::_updateCamera()
{
  if (this->boundShaderID == 0 || this->boundCamera == NULL) {
    return;
  }

  if (kdr::Keys::isPressed(this->glfwWindow, this->cameraBindKey))
  {
    this->boundCamera->setLocked(true);
  }
  else if (kdr::Keys::isPressed(this->glfwWindow, this->cameraUnbindKey))
  {
    this->boundCamera->setLocked(false);
  }

  this->boundCamera->handleMouse(this->glfwWindow);
  this->boundCamera->handleKeyboard(this->glfwWindow, this->deltaTime);
  this->boundCamera->updateMatrix();
  this->boundCamera->applyMatrix(this->boundShaderID, "cameraMatrix");
}

void kdr::Window::_update()
{
  glfwPollEvents();
  this->_updateDeltaTime();
  this->_updateCamera();
  this->update();
}

void kdr::Window::_render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  this->render();
  glfwSwapBuffers(this->glfwWindow);
}
