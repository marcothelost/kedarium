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
  }
}

#endif // KDR_GRAPHICS_HPP
