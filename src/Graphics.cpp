#include "Kedarium/Graphics.hpp"

kdr::Graphics::Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  std::string vertexShaderString = kdr::File::getContents(vertexPath);
  std::string fragmentShaderString = kdr::File::getContents(fragmentPath);

  const char* vertexShaderSource = vertexShaderString.c_str();
  const char* fragmentShaderSource = fragmentShaderString.c_str();

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Info Log
  char infoLog[512];
  int success {0};

  // Vertex Shader Validation
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the vertex shader (\"" << vertexPath << "\")!\n";
    std::cerr << "Error:\n" << infoLog << "\n";
  }

  // Fragment Shader Validation
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the fragment shader (\"" << fragmentPath << "\")!\n";
    std::cerr << "Error:\n" << infoLog << "\n";
  }

  // Shader Program
  this->ID = glCreateProgram();
  glAttachShader(this->ID, vertexShader);
  glAttachShader(this->ID, fragmentShader);
  glLinkProgram(this->ID);

  // Shader Program Validation
  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
    std::cerr << "Failed to link the shader program!\n";
    std::cerr << "Error:\n" << infoLog << "\n";
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

kdr::Graphics::VBO::VBO(GLfloat vertices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  this->Bind();
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  this->Unbind();
}

kdr::Graphics::EBO::EBO(GLuint indices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  this->Bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  this->Unbind();
}

void kdr::Graphics::VAO::LinkAttrib(const kdr::Graphics::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset) const
{
  VBO.Bind();
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

kdr::Graphics::Texture::Texture(const std::string& pngPath, GLenum type, GLenum slot, GLenum pixelType) : type(type)
{
  int imgWidth {0};
  int imgHeight {0};
  bool hasAlpha {false};
  GLubyte* imgData {NULL};

  kdr::Image::loadFromPNG(
    pngPath,
    &imgData,
    imgWidth,
    imgHeight,
    hasAlpha
  );
  if (!imgData) return;

  glGenTextures(1, &this->ID);
  glActiveTexture(slot);
  this->Bind();

  glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(
    this->type,
    0,
    GL_RGBA,
    imgWidth,
    imgHeight,
    0,
    hasAlpha ? GL_RGBA : GL_RGB,
    pixelType,
    imgData
  );
  glGenerateMipmap(this->type);

  delete imgData;
  this->Unbind();
}
