#include "Kedarium/Window.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  kdr::Window* windowInstance = (kdr::Window*)glfwGetWindowUserPointer(window);

  windowInstance->setWidth(width);
  windowInstance->setHeight(height);
  windowInstance->onResize();

  if (windowInstance->getBoundCamera() != NULL)
  {
    windowInstance->getBoundCamera()->setBufferWidth((float)width);
    windowInstance->getBoundCamera()->setBufferHeight((float)height);
  }
  glViewport(
    0,
    0,
    width,
    height
  );
}

void kdr::Window::loop()
{
  while (!glfwWindowShouldClose(this->glfwWindow))
  {
    this->_update();
    this->_render();
  }
}

void kdr::Window::maximize()
{
  GLFWmonitor* monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor);
  glfwSetWindowMonitor(
    this->glfwWindow,
    monitor,
    0,
    0,
    mode->width,
    mode->height,
    mode->refreshRate
  );
  this->fullscreenEnabled = true;
}

void kdr::Window::unmaximize()
{
  GLFWmonitor* monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor);
  glfwSetWindowMonitor(
    this->glfwWindow,
    NULL,
    mode->width / 2 - 400,
    mode->height / 2 - 300,
    800,
    600,
    GLFW_DONT_CARE
  );
  this->fullscreenEnabled = false;
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
  glfwSetWindowUserPointer(this->glfwWindow, this);
  return true;
}

bool kdr::Window::_initializeOpenGLSettings()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glEnable(GL_MULTISAMPLE);

  glCullFace(GL_BACK);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
  if (this->boundShader == NULL || this->boundCamera == NULL) {
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

  if (kdr::Keys::isPressed(this->glfwWindow, this->fullscreenKey))
  {
    if (!this->canUseFullscreen)
    {
      return;
    }
    this->fullscreenEnabled
      ? this->unmaximize()
      : this->maximize();
    this->canUseFullscreen = false;
  }
  else
  {
    this->canUseFullscreen = true;
  }

  this->boundCamera->handleMouse(this->glfwWindow);
  this->boundCamera->handleKeyboard(this->glfwWindow, this->deltaTime);
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->use3D();
  this->render();
  glfwSwapBuffers(this->glfwWindow);
}
