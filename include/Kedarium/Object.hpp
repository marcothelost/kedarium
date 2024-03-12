#ifndef KDR_OBJECT_HPP
#define KDR_OBJECT_HPP

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

namespace kdr
{
  namespace Object
  {
    bool loadFromObj(const std::string& objPath, GLfloat* oVertices, GLsizeiptr& oVerticesSize, GLuint* oIndices, GLsizeiptr& oIndicesSize);
  }
}

#endif // KDR_OBJECT_HPP
