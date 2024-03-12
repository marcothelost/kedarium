#ifndef KDR_SOLIDS_HPP
#define KDR_SOLIDS_HPP

#include <GL/glew.h>
#include <string>

#include "Graphics.hpp"
#include "Space.hpp"
#include "Debug.hpp"

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

        /**
         * @brief Initializes the member objects of the solid with provided vertex and index data.
         * 
         * This function initializes the vertex array object (VAO), vertex buffer object (VBO), and element buffer object (EBO)
         * with the provided vertex and index data.
         * 
         * @param vertices An array containing the vertex data.
         * @param verticesSize The size of the vertex data array in bytes.
         * @param indices An array containing the index data.
         * @param indicesSize The size of the index data array in bytes.
         */
        void initializeMembers(GLfloat* vertices, GLsizeiptr verticesSize, GLuint* indices, GLsizeiptr indicesSize);

      private:
        kdr::Space::Vec3 position {0.f};
        kdr::Space::Mat4 model    {1.f};
    };

    /**
     * @brief Represents a 3D cube.
     */
    class Cube : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a Cube object with the specified position and edge length.
         * 
         * @param position The position of the cube.
         * @param edgeLength The length of each edge of the cube.
         */
        Cube(const kdr::Space::Vec3& position, const float edgeLength);

        /**
         * @brief Renders the cube.
         */
        void render();
    };

    /**
     * @brief Represents a 3D cuboid.
     */
    class Cuboid : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a Cuboid object with the specified position and dimensions.
         * 
         * @param position The position of the cuboid.
         * @param length The length of the cuboid along the x-axis.
         * @param height The height of the cuboid along the y-axis.
         * @param width The width of the cuboid along the z-axis.
         */
        Cuboid(const kdr::Space::Vec3& position, const float length, const float height, const float width);

        /**
         * @brief Renders the cuboid.
         */
        void render();
    };

    /**
     * @brief A class representing a plane in 3D space.
     */
    class Plane : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a Plane object with the specified position, length, and width.
         * 
         * @param position The position of the plane.
         * @param length The length of the plane.
         * @param width The width of the plane.
         */
        Plane(const kdr::Space::Vec3& position, const float length, const float width);

        /**
         * @brief Renders the plane.
         */
        void render();
    };
  }
}

#endif // KDR_SOLIDS_HPP
