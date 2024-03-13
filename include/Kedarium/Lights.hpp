#ifndef KDR_LIGHTS_HPP
#define KDR_LIGHTS_HPP

#include <GL/glew.h>
#include <string>

#include "Color.hpp"
#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing light-related functionality.
   */
  namespace Lights
  {
    class Light
    {
      public:
        /**
         * @brief Constructs a Light object with the given position and color.
         * 
         * @param position The position of the light.
         * @param color The color of the light.
         */
        Light(const kdr::Space::Vec3& position, const kdr::Color::RGBA& color)
        : position(position), color(color)
        {}

        /**
         * @brief Applies the light properties to the specified shader program.
         * 
         * @param shaderID The ID of the shader program.
         * @param positionUniform The name of the uniform variable for the light position.
         * @param colorUniform The name of the uniform variable for the light color.
         */
        void apply(const GLuint shaderID, const std::string& positionUniform, const std::string& colorUniform) const
        {
          GLuint lightPosLoc = glGetUniformLocation(shaderID, positionUniform.c_str());
          GLuint lightColLoc = glGetUniformLocation(shaderID, colorUniform.c_str());

          glUniform3f(lightPosLoc, this->position.x, this->position.y, this->position.z);
          glUniform3f(lightColLoc, this->color.red, this->color.green, this->color.blue);
        }

      private:
        kdr::Space::Vec3 position {0.f};
        kdr::Color::RGBA color    {kdr::Color::White};
    };
  }
}

#endif // KDR_LIGHTS_HPP
