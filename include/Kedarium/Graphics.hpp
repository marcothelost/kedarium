#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <iostream>
#include <string>

#include "File.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing graphics-related functionality.
   */
  namespace Graphics
  {
    /**
     * @brief Class representing a shader program.
     */
    class Shader
    {
      public:
        /**
         * @brief Constructs a Shader object by loading and compiling vertex and fragment shaders.
         *
         * @param vertexPath The file path to the vertex shader source code.
         * @param fragmentPath The file path to the fragment shader source code.
         */
        Shader(const std::string& vertexPath, const std::string& fragmentPath);

        /**
         * @brief Activates the shader program for use.
         */
        void Use()
        { glUseProgram(this->ID); }
        /**
         * @brief Deletes the shader program.
         */
        void Delete()
        { glDeleteProgram(this->ID); }

      private:
        GLuint ID;
    };

    /**
     * @brief Class representing a Vertex Buffer Object (VBO).
     */
    class VBO
    {
      public:
        /**
         * @brief Constructs a VBO object and initializes it with provided vertex data.
         *
         * @param vertices An array containing the vertex data.
         * @param size The size of the vertex data array in bytes.
         */
        VBO(GLfloat vertices[], GLsizeiptr size);

        /**
         * @brief Binds the VBO for use.
         */
        void Bind()
        { glBindBuffer(GL_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the VBO.
         */
        void Unbind()
        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the VBO.
         */
        void Delete()
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * @brief Class representing an Element Buffer Object (EBO).
     */
    class EBO
    {
      public:
        /**
         * @brief Constructs an EBO object and initializes it with provided index data.
         *
         * @param indices An array containing the index data.
         * @param size The size of the index data array in bytes.
         */
        EBO(GLuint indices[], GLsizeiptr size);

        /**
         * @brief Binds the EBO for use.
         */
        void Bind()
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the EBO.
         */
        void Unbind()
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the EBO.
         */
        void Delete()
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
