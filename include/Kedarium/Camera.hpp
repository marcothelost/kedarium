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
       * @param bufferWidth The width of the rendering buffer.
       * @param bufferHeight The height of the rendering buffer.
       * @param zNear The near clipping plane.
       * @param zFar The far clipping plane.
       * @param speed The movement speed of the camera.
       * @param sensitivity The mouse sensitivity of the camera.
       */
      Camera(const float fov, const float bufferWidth, const float bufferHeight, const float zNear, const float zFar, const float speed, const float sensitivity)
      : fov(fov), bufferWidth(bufferWidth), bufferHeight(bufferHeight), zNear(zNear), zFar(zFar), speed(speed), sensitivity(sensitivity)
      {}

      /**
       * @brief Gets the field of view angle of the camera.
       * 
       * @return The field of view angle in degrees.
       */
      float getFov() const
      { return this->fov; }
      /**
       * @brief Gets the width of the rendering buffer.
       * 
       * @return The width of the rendering buffer.
       */
      float getBufferWidth() const
      { return this->bufferWidth; }
      /**
       * @brief Gets the height of the rendering buffer.
       * 
       * @return The height of the rendering buffer.
       */
      float getBufferHeight() const
      { return this->bufferHeight; }
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
       * @brief Gets the mouse sensitivity of the camera.
       * 
       * @return The mouse sensitivity of the camera.
       */
      float getSensitivity() const
      { return this->sensitivity; }
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
       * @brief Sets the width of the rendering buffer.
       * 
       * @param bufferWidth The new width of the rendering buffer.
       */
      void setBufferWidth(const float bufferWidth)
      { this->bufferWidth = bufferWidth; this->aspect = this->bufferWidth / this->bufferHeight; }
      /**
       * @brief Sets the height of the rendering buffer.
       * 
       * @param bufferHeight The new height of the rendering buffer.
       */
      void setBufferHeight(const float bufferHeight)
      { this->bufferHeight = bufferHeight; this->aspect = this->bufferWidth / this->bufferHeight; }
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
       * @brief Sets the mouse sensitivity of the camera.
       * 
       * @param sensitivity The new mouse sensitivity of the camera.
       */
      void setSensitivity(const float sensitivity)
      { this->sensitivity = sensitivity; }
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
       * @brief Updates the transformation matrix for 2D rendering.
       */
      void updateMatrix2D();
      /**
       * @brief Updates the transformation matrix for 3D rendering.
       */
      void updateMatrix3D();
      /**
       * @brief Applies the camera matrix to a shader uniform.
       * 
       * @param shaderID The ID of the shader program.
       * @param uniformName The name of the uniform variable in the shader.
       */
      void applyMatrix(const GLuint shaderID, const std::string& uniformName);

    private:
      float fov          {60.f};
      float bufferWidth  {800.f};
      float bufferHeight {800.f};
      float zNear        {0.1f};
      float zFar         {100.f};
      float speed        {5.f};
      float sensitivity  {10.f};
      float aspect       {1.f};

      kdr::Space::Vec3 position {0.f, 0.f,  3.f};
      kdr::Space::Vec3 front    {0.f, 0.f, -1.f};
      kdr::Space::Vec3 up       {0.f, 1.f,  0.f};
      kdr::Space::Mat4 matrix   {1.f};

      float yaw   {-90.f};
      float pitch {0.f};

      bool locked {false};
  };
}

#endif // KDR_CAMERA_HPP
