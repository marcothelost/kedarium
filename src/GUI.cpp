#include "Kedarium/GUI.hpp"

GLuint elementIndices[] = {
  0, 1, 3,
  0, 3, 2,
};

kdr::GUI::Element::Element(const kdr::Space::Vec2& position, float width, const float height) : position(position)
{
  GLfloat elementVertices[] = {
    0.f,    height, 0.f, 0.f, // 0 00
    width,  height, 1.f, 0.f, // 1 10
    0.f,    0.f,    0.f, 1.f, // 2 01
    width,  0.f,    1.f, 1.f, // 3 11
  };

  this->VAO = new kdr::Graphics::VAO();
  this->VBO = new kdr::Graphics::VBO(elementVertices, sizeof(elementVertices));
  this->EBO = new kdr::Graphics::EBO(elementIndices, sizeof(elementIndices));

  this->VAO->Bind();
  this->VBO->Bind();
  this->EBO->Bind();

  this->VAO->LinkAttrib(*VBO, 0, 2, GL_FLOAT, 4 * sizeof(GLfloat), (void*)0);
  this->VAO->LinkAttrib(*VBO, 1, 2, GL_FLOAT, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

  this->VAO->Unbind();
  this->VBO->Unbind();
  this->EBO->Unbind();
}

void kdr::GUI::Element::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(elementIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}
