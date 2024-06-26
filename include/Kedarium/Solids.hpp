#ifndef KDR_SOLIDS_HPP
#define KDR_SOLIDS_HPP

#include <GL/glew.h>
#include <vector>
#include <string>

#include "Graphics.hpp"
#include "Space.hpp"
#include "Object.hpp"

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
          this->position += vec;
        }
        /**
         * @brief Rotates the solid object around the X-axis by the given angle.
         * 
         * @param degrees The angle of rotation in degrees.
         */
        void rotateX(const float degrees)
        { this->model = kdr::Space::rotate(this->model, degrees, {1.f, 0.f, 0.f}); }
        /**
         * @brief Rotates the solid object around the Y-axis by the given angle.
         * 
         * @param degrees The angle of rotation in degrees.
         */
        void rotateY(const float degrees)
        { this->model = kdr::Space::rotate(this->model, degrees, {0.f, 1.f, 0.f}); }
        /**
         * @brief Rotates the solid object around the Z-axis by the given angle.
         * 
         * @param degrees The angle of rotation in degrees.
         */
        void rotateZ(const float degrees)
        { this->model = kdr::Space::rotate(this->model, degrees, {0.f, 0.f, 1.f}); }

        /**
         * @brief Applies the model matrix to the shader program.
         *
         * @param shaderID The ID of the shader program.
         * @param uniform The name of the uniform variable in the shader program.
         */
        void applyModelMatrix(const GLuint shaderID, const std::string& uniform) const
        {
          kdr::Space::Mat4 usedMatrix = kdr::Space::translate(this->model, this->position);
          GLuint modelLoc = glGetUniformLocation(shaderID, uniform.c_str());
          glUniformMatrix4fv(modelLoc, 1, GL_FALSE, kdr::Space::valuePointer(usedMatrix));
        }
        /**
         * @brief Renders the solid object.
         * 
         * This function should be implemented by subclasses to render the solid object.
         */
        virtual void render() const = 0;

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
        void render() const;
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
        void render() const;
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
        void render() const;
    };

    /**
     * @brief A class representing a pyramid in 3D space.
     */
    class Pyramid : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a Pyramid object with the specified position, edge length, and height.
         * 
         * @param position The position of the pyramid.
         * @param edgeLength The length of the edges of the pyramid's base.
         * @param height The height of the pyramid.
         */
        Pyramid(const kdr::Space::Vec3& position, const float edgeLength, const float height);

        /**
         * @brief Renders the pyramid.
         * 
         * This function renders the pyramid using OpenGL.
         */
        void render() const;
    };

    /**
     * @brief Class representing a mesh loaded from an OBJ file.
     */
    class Mesh : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a Mesh object from an OBJ file.
         * 
         * @param position The position of the mesh in 3D space.
         * @param objPath The path to the OBJ file containing the mesh data.
         * @param dimensions The dimensions of the mesh in 3D space, extracted from the OBJ file if not provided.
         */
        Mesh(const kdr::Space::Vec3& position, const std::string objPath, const kdr::Space::Vec3& dimensions = {0.f, 0.f, 0.f});

        /**
         * @brief Renders the mesh.
         */
        void render() const;

      private:
        unsigned int indexCount {0};
    };
  }
}

#endif // KDR_SOLIDS_HPP
