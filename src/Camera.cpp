#include "Kedarium/Camera.hpp"

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
