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
  /**
   * @brief Namespace containing functionality related to object loading.
   */
  namespace Object
  {
    /**
     * @brief Loads vertex and index data from an OBJ file.
     * 
     * @param objPath The path to the OBJ file to load.
     * @param oVertices A reference to a vector to store the loaded vertex data.
     * @param oVerticesSize A reference to a variable to store the size of the loaded vertex data in bytes.
     * @param oIndices A reference to a vector to store the loaded index data.
     * @param oIndicesSize A reference to a variable to store the size of the loaded index data in bytes.
     * @return True if the loading is successful, false otherwise.
     */
    bool loadFromObj(const std::string& objPath, std::vector<GLfloat>& oVertices, GLsizeiptr& oVerticesSize, std::vector<GLuint>& oIndices, GLsizeiptr& oIndicesSize);
  }
}

#endif // KDR_OBJECT_HPP
