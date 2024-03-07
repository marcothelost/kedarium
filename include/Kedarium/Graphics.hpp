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
        void Use() const
        { glUseProgram(this->ID); }
        /**
         * @brief Deletes the shader program.
         */
        void Delete() const
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
        void Bind() const
        { glBindBuffer(GL_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the VBO.
         */
        void Unbind() const
        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the VBO.
         */
        void Delete() const
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
        void Bind() const
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the EBO.
         */
        void Unbind() const
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the EBO.
         */
        void Delete() const
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * @brief Class representing a Vertex Array Object (VAO).
     */
    class VAO
    {
      public:
        /**
         * @brief Constructs a VAO object.
         * 
         * This constructor generates a new VAO ID.
         */
        VAO()
        { glGenVertexArrays(1, &this->ID); }

        /**
         * @brief Binds the VAO for use.
         */
        void Bind() const
        { glBindVertexArray(this->ID); }
        /**
         * @brief Unbinds the VAO.
         */
        void Unbind() const
        { glBindVertexArray(0); }
        /**
         * @brief Deletes the VAO.
         */
        void Delete() const
        { glDeleteVertexArrays(1, &this->ID); }
        /**
         * @brief Links a vertex buffer object (VBO) to a layout in the VAO.
         *
         * @param VBO The VBO to link.
         * @param layout The layout location.
         * @param size The size of each element.
         * @param type The data type of the elements.
         * @param stride The stride between consecutive elements.
         * @param offset The offset of the first element in the buffer.
         */
        void LinkAttrib(const kdr::Graphics::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset) const;

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
