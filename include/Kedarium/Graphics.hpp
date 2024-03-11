#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <iostream>
#include <string>

#include "File.hpp"
#include "Image.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing graphics-related functionality.
   */
  namespace Graphics
  {
    /**
     * @brief Sets the OpenGL rendering mode to point mode.
     */
    inline void usePointMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); }
    /**
     * @brief Sets the OpenGL rendering mode to line mode.
     */
    inline void useLineMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
    /**
     * @brief Sets the OpenGL rendering mode to fill mode.
     */
    inline void useFillMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

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
         * @brief Gets the ID of the shader program.
         * 
         * @return The ID of the shader program.
         */
        GLuint getID() const
        { return this->ID; }

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
         * @brief Gets the ID of the vertex buffer object.
         * 
         * @return The ID of the vertex buffer object.
         */
        GLuint getID() const
        { return this->ID; }

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
         * @brief Gets the ID of the element buffer object.
         * 
         * @return The ID of the element buffer object.
         */
        GLuint getID() const
        { return this->ID; }

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
         * @brief Gets the ID of the vertex array object.
         * 
         * @return The ID of the vertex array object.
         */
        GLuint getID() const
        { return this->ID; }

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

    /**
     * @brief Represents a texture in OpenGL.
     */
    class Texture
    {
      public:
        /**
         * @brief Constructs a Texture object from a PNG file.
         * 
         * @param pngPath The file path to the PNG texture.
         * @param type The type of the texture.
         * @param slot The texture slot.
         * @param pixelType The pixel type of the texture.
         */
        Texture(const std::string& pngPath, GLenum type, GLenum slot, GLenum pixelType);

        /**
         * @brief Binds the texture.
         */
        void Bind() const
        { glBindTexture(this->type, this->ID); }
        /**
         * @brief Unbinds the texture.
         */
        void Unbind() const
        { glBindTexture(this->type, 0); }
        /**
         * @brief Deletes the texture.
         */
        void Delete() const
        { glDeleteTextures(1, &this->ID); }
        /**
         * @brief Sets the texture unit in the shader.
         * 
         * @param shaderID The ID of the shader program.
         * @param uniform The name of the uniform variable in the shader.
         * @param unit The texture unit to set.
         */
        void TextureUnit(const GLuint shaderID, const std::string& uniform, GLuint unit) const
        {
          GLuint textureUnitLoc = glGetUniformLocation(shaderID, uniform.c_str());
          glUniform1i(textureUnitLoc, unit);
        }

      private:
        GLuint ID;
        GLenum type;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
