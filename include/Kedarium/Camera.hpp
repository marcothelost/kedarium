#ifndef KDR_CAMERA_HPP
#define KDR_CAMERA_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "Space.hpp"
#include "Keys.hpp"

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
       * @param speed The movement speed of the camera.
       */
      Camera(const float fov, const float aspect, const float zNear, const float zFar, const float speed)
      : fov(fov), aspect(aspect), zNear(zNear), zFar(zFar), speed(speed)
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
       * @brief Gets the movement speed of the camera.
       * 
       * @return The movement speed of the camera.
       */
      float getSpeed() const
      { return this->speed; }
      /**
       * @brief Checks if the camera movement is locked.
       * 
       * @return True if camera movement is locked, false otherwise.
       */
      bool getLocked() const
      { return this->locked; }

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
       * @brief Sets the movement speed of the camera.
       * 
       * @param speed The new movement speed of the camera.
       */
      void setSpeed(const float speed)
      { this->speed = speed; }
      /**
       * @brief Sets whether the camera movement is locked.
       * 
       * @param locked True to lock camera movement, false otherwise.
       */
      void setLocked(const bool locked)
      { this->locked = locked; }

      /**
       * @brief Handles keyboard input for camera movement.
       * 
       * This function handles keyboard input for camera movement, using the specified delta time.
       * 
       * @param window A pointer to the GLFW window.
       * @param deltaTime The time elapsed since the last frame.
       */
      void handleKeyboard(GLFWwindow* window, const float deltaTime);
      /**
       * @brief Handles mouse input for camera rotation.
       * 
       * This function handles mouse input for camera rotation.
       * 
       * @param window A pointer to the GLFW window.
       */
      void handleMouse(GLFWwindow* window);
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
      float speed  {5.f};

      kdr::Space::Vec3 position {0.f, 0.f, -3.f};
      kdr::Space::Mat4 matrix  {1.f};

      bool locked {false};
  };
}

#endif // KDR_CAMERA_HPP
