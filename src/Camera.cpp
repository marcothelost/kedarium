#include "Kedarium/Camera.hpp"

void kdr::Camera::handleMouse(GLFWwindow* window)
{
  if (!this->locked)
  {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    return;
  }
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  double mouseX;
  double mouseY;
  glfwGetCursorPos(window, &mouseX, &mouseY);

  int windowWidth;
  int windowHeight;
  glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

  const float deltaX = (float)(mouseX - ((float)windowWidth / 2.f));
  const float deltaY = (float)(mouseY - ((float)windowHeight / 2.f));

  this->yaw += deltaX * this->sensitivity;
  this->pitch -= deltaY * this->sensitivity;

  if (this->pitch > 89.f)
  {
    this->pitch = 89.f;
  }
  else if (this->pitch < -89.f)
  {
    this->pitch = -89.f;
  }
  this->yaw = std::remainderf(this->yaw, 360.f);

  glfwSetCursorPos(window, (double)windowWidth / 2.f, (double)windowHeight / 2.f);
}

void kdr::Camera::handleKeyboard(GLFWwindow* window, const float deltaTime)
{
  if (!this->locked)
  {
    return;
  }

  if (kdr::Keys::isPressed(window, kdr::Key::W))
  {
    this->position += this->front * this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::S))
  {
    this->position -= this->front * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::A))
  {
    this->position -= kdr::Space::cross(this->front, this->up) * this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::D))
  {
    this->position += kdr::Space::cross(this->front, this->up) * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::Spacebar))
  {
    this->position += this->up * this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::LeftShift))
  {
    this->position -= this->up * this->speed * deltaTime;
  }
}

void kdr::Camera::updateMatrix2D()
{
  kdr::Space::Mat4 view       {1.f};
  kdr::Space::Mat4 projection {1.f};

  projection = kdr::Space::ortho(
    0.f,
    800.f,
    600.f,
    0.f,
    -1.f,
    1.f
  );

  this->matrix = projection * view;
}

void kdr::Camera::updateMatrix3D()
{
  kdr::Space::Mat4 view       {1.f};
  kdr::Space::Mat4 projection {1.f};
  kdr::Space::Vec3 tempFront  {0.f};

  tempFront.x = cos(kdr::Space::radians(this->yaw)) * cos(kdr::Space::radians(this->pitch));
  tempFront.y = sin(kdr::Space::radians(this->pitch));
  tempFront.z = sin(kdr::Space::radians(this->yaw)) * cos(kdr::Space::radians(this->pitch));

  this->front = kdr::Space::normalize(tempFront);

  view = kdr::Space::lookAt(
    this->position,
    this->position + this->front,
    this->up
  );
  projection = kdr::Space::perspective(
    this->fov,
    this->aspect,
    this->zNear, 
    this->zFar
  );

  this->matrix = projection * view;
}

void kdr::Camera::applyMatrix(const GLuint shaderID, const std::string& uniformName)
{
  GLuint matrixLoc = glGetUniformLocation(shaderID, uniformName.c_str());
  glUniformMatrix4fv(matrixLoc, 1, GL_FALSE, kdr::Space::valuePointer(this->matrix));
}
