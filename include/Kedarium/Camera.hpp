#ifndef KDR_CAMERA_HPP
#define KDR_CAMERA_HPP

#include <GL/glew.h>
#include <string>

#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Class representing a camera in 3D space.
   */
  class Camera
  {
    public:
      /**
       * @brief Default constructor.
       */
      Camera()
      {}
      /**
       * @brief Constructs a camera with specified parameters.
       * 
       * @param fov The field of view angle in degrees.
       * @param aspect The aspect ratio of the viewport (width / height).
       * @param zNear The near clipping plane.
       * @param zFar The far clipping plane.
       */
      Camera(const float fov, const float aspect, const float zNear, const float zFar)
      : fov(fov), aspect(aspect), zNear(zNear), zFar(zFar)
      {}

      /**
       * @brief Gets the field of view angle of the camera.
       * 
       * @return The field of view angle in degrees.
       */
      float getFov() const
      { return this->fov; }
      /**
       * @brief Gets the aspect ratio of the camera viewport.
       * 
       * @return The aspect ratio of the viewport (width / height).
       */
      float getAspect() const
      { return this->aspect; }
      /**
       * @brief Gets the near clipping plane of the camera.
       * 
       * @return The near clipping plane distance.
       */
      float getZNear() const
      { return this->zNear; }
      /**
       * @brief Gets the far clipping plane of the camera.
       * 
       * @return The far clipping plane distance.
       */
      float getZFar() const
      { return this->zFar; }

      /**
       * @brief Sets the field of view angle of the camera.
       * 
       * @param fov The new field of view angle in degrees.
       */
      void setFov(const float fov)
      { this->fov = fov; }
      /**
       * @brief Sets the aspect ratio of the camera viewport.
       * 
       * @param aspect The new aspect ratio of the viewport (width / height).
       */
      void setAspect(const float aspect)
      { this->aspect = aspect; }
      /**
       * @brief Sets the near clipping plane of the camera.
       * 
       * @param zNear The new near clipping plane distance.
       */
      void setZNear(const float zNear)
      { this->zNear = zNear; }
      /**
       * @brief Sets the far clipping plane of the camera.
       * 
       * @param zFar The new far clipping plane distance.
       */
      void setZFar(const float zFar)
      { this->zFar = zFar; }

      /**
       * @brief Updates the camera matrix.
       */
      void updateMatrix();
      /**
       * @brief Applies the camera matrix to a shader uniform.
       * 
       * @param shaderID The ID of the shader program.
       * @param uniformName The name of the uniform variable in the shader.
       */
      void applyMatrix(const GLuint shaderID, const std::string& uniformName);

    private:
      float fov    {60.f};
      float aspect {1.f};
      float zNear  {0.1f};
      float zFar   {100.f};

      kdr::Space::Vec3 position {0.f, 0.f, -3.f};
      kdr::Space::Mat4 matrix  {1.f};
  };
}

#endif // KDR_CAMERA_HPP
