#include "Kedarium/Solids.hpp"

constexpr float CUBE_NORMAL_FACTOR = 0.57735f;

void kdr::Solids::Solid::initializeMembers(GLfloat* vertices, GLsizeiptr verticesSize, GLuint* indices, GLsizeiptr indicesSize)
{
  this->VAO = new kdr::Graphics::VAO();
  this->VBO = new kdr::Graphics::VBO(vertices, verticesSize);
  this->EBO = new kdr::Graphics::EBO(indices, indicesSize);

  this->VAO->Bind();
  this->VBO->Bind();
  this->EBO->Bind();

  this->VAO->LinkAttrib(*VBO, 0, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)0);
  this->VAO->LinkAttrib(*VBO, 1, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  this->VAO->LinkAttrib(*VBO, 2, 2, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
  this->VAO->LinkAttrib(*VBO, 3, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(8 * sizeof(GLfloat)));

  this->VAO->Unbind();
  this->VBO->Unbind();
  this->EBO->Unbind();
}

GLuint cuboidIndices[] = {
  0, 3, 9,    // Front
  0, 9, 6,    // Front
  4, 16, 22,  // Right
  4, 22, 10,  // Right
  15, 12, 18, // Back
  15, 18, 21, // Back
  13, 1, 7,   // Left
  13, 7, 19,  // Left
  8, 11, 23,  // Top
  8, 23, 20,  // Top
  14, 17, 5,  // Bottom
  14, 5, 2,   // Bottom
};

kdr::Solids::Cube::Cube(const kdr::Space::Vec3& position, const float edgeLength) : kdr::Solids::Solid(position)
{
  GLfloat cubeVertices[] = {
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 0  000 Front
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 1  000 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 2  000 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 3  100 Front
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 4  100 Right
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 5  100 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 6  010 Front
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 7  010 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 8  010 Top
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 9  110 Front
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 10 110 Right
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 11 110 Top
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 12 001 Back
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 13 001 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 14 001 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 15 101 Back
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 16 101 Right
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 17 101 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 18 011 Back
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 19 011 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 20 011 Top
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 21 111 Back
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 22 111 Right
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 23 111 Top
  };
  this->initializeMembers(cubeVertices, sizeof(cubeVertices), cuboidIndices, sizeof(cuboidIndices));
}

void kdr::Solids::Cube::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(cuboidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

kdr::Solids::Cuboid::Cuboid(const kdr::Space::Vec3& position, const float length, const float height, const float width) : kdr::Solids::Solid(position)
{
  GLfloat cuboidVertices[] = {
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,    -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 0  000 Front
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, width,  0.f,    -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 1  000 Left
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, length, width,  -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 2  000 Bottom
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, length, 0.f,     CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 3  100 Front
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,     CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 4  100 Right
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    width,   CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 5  100 Bottom
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    height, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 6  010 Front
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, width,  height, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 7  010 Left
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,    -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 8  010 Top
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, length, height,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 9  110 Front
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    height,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 10 110 Right
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, length, 0.f,     CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, // 11 110 Top
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, length, 0.f,    -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 12 001 Back
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,    -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 13 001 Left
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, length, 0.f,    -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 14 001 Bottom
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,     CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 15 101 Back
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, width,  0.f,     CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 16 101 Right
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,     CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 17 101 Bottom
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, length, height, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 18 011 Back
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    height, -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 19 011 Left
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    width,  -CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 20 011 Top
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    height,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 21 111 Back
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, width,  height,  CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 22 111 Right
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, length, width,   CUBE_NORMAL_FACTOR,  CUBE_NORMAL_FACTOR, -CUBE_NORMAL_FACTOR, // 23 111 Top
  };
  this->initializeMembers(cuboidVertices, sizeof(cuboidVertices), cuboidIndices, sizeof(cuboidIndices));
}

void kdr::Solids::Cuboid::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(cuboidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

GLuint planeIndices[] = {
  0, 1, 3, // Top
  0, 3, 2, // Top
  6, 7, 5, // Bottom
  6, 5, 4, // Bottom
};

kdr::Solids::Plane::Plane(const kdr::Space::Vec3& position, const float length, const float width) : kdr::Solids::Solid(position)
{
  GLfloat planeVertices[] = {
    -(length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,   0.f,  1.f, 0.f, // 0 010 Top
     (length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, length, 0.f,   0.f,  1.f, 0.f, // 1 110 Top
    -(length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    width, 0.f,  1.f, 0.f, // 2 011 Top
     (length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, length, width, 0.f,  1.f, 0.f, // 3 111 Top
    -(length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,   0.f, -1.f, 0.f, // 4 000 Bottom
     (length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, length, 0.f,   0.f, -1.f, 0.f, // 5 100 Bottom
    -(length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    width, 0.f, -1.f, 0.f, // 6 001 Bottom
     (length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, length, width, 0.f, -1.f, 0.f, // 7 101 Bottom
  };
  this->initializeMembers(planeVertices, sizeof(planeVertices), planeIndices, sizeof(planeIndices));
}

void kdr::Solids::Plane::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(planeIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

GLuint pyramidIndices[] = {
  0, 3, 12,  // Front
  4, 10, 13, // Right
  9, 6, 14,  // Back
  7, 1, 15,  // Left
  8, 11, 5,  // Bottom
  8, 5, 2,   // Bottom
};

kdr::Solids::Pyramid::Pyramid(const kdr::Space::Vec3& position, const float edgeLength, const float height) : kdr::Solids::Solid(position)
{
  kdr::Space::Vec3 dirVector {
    -(edgeLength / 2.f),
    height,
    (edgeLength / 2.f)
  };
  kdr::Space::Vec3 xEdgeVector  {1.f,  0.f,  0.f};
  kdr::Space::Vec3 zEdgeVector  {0.f,  0.f, -1.f};
  kdr::Space::Vec3 bottomVector {0.f, -1.f,  0.f};
  kdr::Space::Vec3 sumVector = dirVector + xEdgeVector + zEdgeVector + bottomVector;
  kdr::Space::Vec3 normal = kdr::Space::normalize({
    sumVector.x / 4.f,
    sumVector.y / 4.f,
    sumVector.z / 4.f
  });

  GLfloat pyramidVertices[] = {
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, -normal.x,  normal.y,  normal.z, // 0  00 Front
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, -normal.x,  normal.y,  normal.z, // 1  00 Left
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  1.f, -normal.x, -normal.y,  normal.z, // 2  00 Bottom
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  normal.x,  normal.y,  normal.z, // 3  10 Front
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  normal.x,  normal.y,  normal.z, // 4  10 Right
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  1.f,  normal.x, -normal.y,  normal.z, // 5  10 Bottom
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, -normal.x,  normal.y, -normal.z, // 6  01 Back
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, -normal.x,  normal.y, -normal.z, // 7  01 Left
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, -normal.x, -normal.y, -normal.z, // 8  01 Bottom
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  normal.x,  normal.y, -normal.z, // 9  11 Back
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  normal.x,  normal.y, -normal.z, // 10 11 Right
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  normal.x, -normal.y, -normal.z, // 11 11 Bottom
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,   0.f,      1.f,       0.f,      // 12 Top (Front)
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,   0.f,      1.f,       0.f,      // 13 Top (Right)
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,   0.f,      1.f,       0.f,      // 14 Top (Back)
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,   0.f,      1.f,       0.f,      // 15 Top (Left)
  };
  this->initializeMembers(pyramidVertices, sizeof(pyramidVertices), pyramidIndices, sizeof(pyramidIndices));
}

void kdr::Solids::Pyramid::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(pyramidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

kdr::Solids::Mesh::Mesh(const kdr::Space::Vec3& position, const std::string objPath) : kdr::Solids::Solid(position)
{
  std::vector<GLfloat> vertices;
  std::vector<GLuint>  indices;
  GLsizeiptr verticesSize {0};
  GLsizeiptr indicesSize  {0};

  kdr::Object::loadFromObj(objPath, vertices, verticesSize, indices, indicesSize);
  this->initializeMembers(&vertices[0], verticesSize, &indices[0], indicesSize);
  this->indexCount = indices.size();
}

void kdr::Solids::Mesh::render() const
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, this->indexCount * sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}
