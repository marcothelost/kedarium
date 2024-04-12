#ifndef KDR_OBJECT_HPP
#define KDR_OBJECT_HPP

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing functionality related to object loading.
   */
  namespace Object
  {
    /**
     * @brief Loads vertex and index data from an OBJ file.
     * 
     * @param objPath The path to the OBJ file to load.
     * @param oVertices Vector to store the loaded vertex data.
     * @param oVerticesSize Variable to store the size of the loaded vertex data in bytes.
     * @param oIndices Vector to store the loaded index data.
     * @param oIndicesSize Variable to store the size of the loaded index data in bytes.
     * @param dimensions The dimensions of the mesh in 3D space, extracted from the OBJ file if not provided.
     * @return True if the loading is successful, false otherwise.
     */
    bool loadFromObj(const std::string& objPath, std::vector<GLfloat>& oVertices, GLsizeiptr& oVerticesSize, std::vector<GLuint>& oIndices, GLsizeiptr& oIndicesSize, const kdr::Space::Vec3& dimensions = {0.f, 0.f, 0.f});
  }
}

#endif // KDR_OBJECT_HPP
