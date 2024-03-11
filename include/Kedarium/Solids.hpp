#ifndef KDR_SOLIDS_HPP
#define KDR_SOLIDS_HPP

#include <GL/glew.h>
#include <string>

#include "Graphics.hpp"
#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing classes related to solid objects.
   */
  namespace Solids
  {
    /**
     * @brief Base class for solid objects.
     */
    class Solid
    {
      public:
        /**
         * @brief Constructs a solid object at the specified position.
         *
         * @param position The position of the solid object.
         */
        Solid(const kdr::Space::Vec3& position)
        {
          this->translate(position);
        }
        /**
         * @brief Destructor for the solid object.
         * 
         * Cleans up allocated resources.
         */
        virtual ~Solid()
        {
          this->VAO->Delete();
          this->VBO->Delete();
          this->EBO->Delete();

          delete this->VAO;
          delete this->VBO;
          delete this->EBO;
        }

        /**
         * @brief Translates the solid object by the given vector.
         *
         * @param vec The translation vector.
         */
        void translate(const kdr::Space::Vec3& vec)
        {
          this->model = kdr::Space::translate(this->model, vec);
        }

        /**
         * @brief Applies the model matrix to the shader program.
         *
         * @param shaderID The ID of the shader program.
         * @param uniform The name of the uniform variable in the shader program.
         */
        void applyModelMatrix(const GLuint shaderID, const std::string& uniform) const
        {
          GLuint modelLoc = glGetUniformLocation(shaderID, uniform.c_str());
          glUniformMatrix4fv(modelLoc, 1, GL_FALSE, kdr::Space::valuePointer(this->model));
        }
        /**
         * @brief Renders the solid object.
         * 
         * This function should be implemented by subclasses to render the solid object.
         */
        virtual void render() = 0;

      protected:
        kdr::Graphics::VAO* VAO {NULL};
        kdr::Graphics::VBO* VBO {NULL};
        kdr::Graphics::EBO* EBO {NULL};

      private:
        kdr::Space::Vec3 position {0.f};
        kdr::Space::Mat4 model    {1.f};
    };
  }
}

#endif // KDR_SOLIDS_HPP
