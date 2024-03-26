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
         * @param intensity The intensity of the light.
         */
        Light(const kdr::Space::Vec3& position, const kdr::Color::RGBA& color, const float intensity)
        : position(position), color(color), intensity(intensity)
        {}

        /**
         * @brief Gets the position of the light.
         * 
         * @return The position of the light.
         */
        kdr::Space::Vec3 getPosition() const
        { return this->position; }

        /**
         * @brief Applies the light properties (position and color) for a specific index in an array to the specified shader program.
         * 
         * @param shaderID The ID of the shader program.
         * @param index The index of the light in the array.
         * @param positionUniform The base name of the uniform variable for the light position in the array.
         * @param colorUniform The base name of the uniform variable for the light color in the array.
         * @param intensityUniform The base name of the uniform variable for the light intensity in the array.
         */
        void apply(const GLuint shaderID, const unsigned int index, const std::string& positionUniform, const std::string& colorUniform, const std::string& intensityUniform) const
        {
          GLuint lightPosLoc = glGetUniformLocation(shaderID, (positionUniform + "[" + std::to_string(index) +"]").c_str());
          GLuint lightColLoc = glGetUniformLocation(shaderID, (colorUniform + "[" + std::to_string(index) +"]").c_str());
          GLuint lightIntLoc = glGetUniformLocation(shaderID, (intensityUniform + "[" + std::to_string(index) +"]").c_str());

          glUniform3f(lightPosLoc, this->position.x, this->position.y, this->position.z);
          glUniform3f(lightColLoc, this->color.red, this->color.green, this->color.blue);
          glUniform1f(lightIntLoc, this->intensity);
        }

      private:
        kdr::Space::Vec3 position  {0.f};
        kdr::Color::RGBA color     {kdr::Color::White};
        float            intensity;
    };
  }
}

#endif // KDR_LIGHTS_HPP
