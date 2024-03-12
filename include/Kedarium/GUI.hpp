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
  }
}

#endif // KDR_GUI_HPP
