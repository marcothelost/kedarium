#include "Kedarium/Camera.hpp"

void kdr::Camera::handleMovement(GLFWwindow* window, const float deltaTime)
{
  if (kdr::Keys::isPressed(window, kdr::Key::W))
  {
    this->position.z += this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::S))
  {
    this->position.z -= this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::A))
  {
    this->position.x += this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::D))
  {
    this->position.x -= this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::Spacebar))
  {
    this->position.y -= this->speed * deltaTime;
  }
  else if (kdr::Keys::isPressed(window, kdr::Key::LeftShift))
  {
    this->position.y += this->speed * deltaTime;
  }
}

void kdr::Camera::updateMatrix()
{
  kdr::Space::Mat4 view       {1.f};
  kdr::Space::Mat4 projection {1.f};

  view = kdr::Space::translate(view, {this->position.x, this->position.y, this->position.z});
  projection = kdr::Space::perspective(this->fov, this->aspect, this->zNear, this->zFar);

  this->matrix = projection * view;
}

void kdr::Camera::applyMatrix(const GLuint shaderID, const std::string& uniformName)
{
  GLuint matrixLoc = glGetUniformLocation(shaderID, uniformName.c_str());
  glUniformMatrix4fv(matrixLoc, 1, GL_FALSE, kdr::Space::valuePointer(this->matrix));
}
