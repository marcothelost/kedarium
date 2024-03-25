#ifndef KDR_GUI_HPP
#define KDR_GUI_HPP

#include <GL/glew.h>

#include "Graphics.hpp"
#include "Space.hpp"

namespace kdr
{
  namespace GUI
  {
    /**
     * @brief Base class for GUI elements.
     */
    class Element
    {
      public:
        /**
         * @brief Constructs an Element object with the given position, width, and height.
         * 
         * @param position The position of the element.
         * @param width The width of the element.
         * @param height The height of the element.
         */
        Element(const kdr::Space::Vec2& position, float width, const float height);
        /**
         * @brief Destructor for Element objects.
         */
        virtual ~Element()
        {
          this->VAO->Delete();
          this->VBO->Delete();
          this->EBO->Delete();

          delete this->VAO;
          delete this->VBO;
          delete this->EBO;
        }

        /**
         * @brief Sets the position of the element.
         * 
         * @param position The new position of the element.
         */
        void setPosition(const kdr::Space::Vec2 position)
        { this->position = position; }

        /**
         * @brief Applies the position of the GUI element to a shader uniform.
         * 
         * @param shaderID The ID of the shader program.
         * @param uniform The name of the uniform variable in the shader.
         */
        void applyPosition(const GLuint shaderID, const std::string& uniform) const
        {
          GLuint positionLoc = glGetUniformLocation(shaderID, uniform.c_str());
          glUniform2f(positionLoc, this->position.x, this->position.y);
        }

        /**
         * @brief Renders the GUI element.
         */
        virtual void render() const;

      private:
        kdr::Graphics::VAO* VAO;
        kdr::Graphics::VBO* VBO;
        kdr::Graphics::EBO* EBO;

        kdr::Space::Vec2 position {0.f};
    };

    /**
     * @brief Represents a crosshair GUI element.
     */
    class Crosshair : public kdr::GUI::Element
    {
      public:
        /**
         * @brief Constructs a Crosshair object.
         * 
         * @param screenDimensions The dimensions of the screen.
         * @param edgeLength The length of each edge of the crosshair.
         */
        Crosshair(const kdr::Space::Vec2& screenDimensions, const float edgeLength)
        : kdr::GUI::Element({
            screenDimensions.x / 2.f - edgeLength / 2.f,
            screenDimensions.y / 2.f - edgeLength / 2.f,
          }, edgeLength, edgeLength), edgeLength(edgeLength)
        {}

        /**
         * @brief Updates the position of the crosshair.
         * 
         * @param screenDimensions The dimensions of the screen.
         */
        void update(const kdr::Space::Vec2& screenDimensions)
        {
          this->setPosition({
            screenDimensions.x / 2.f - this->edgeLength / 2.f,
            screenDimensions.y / 2.f - this->edgeLength / 2.f,
          });
        }

      private:
        float edgeLength {0.f};
    };
  }
}

#endif // KDR_GUI_HPP
