#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Core.hpp"
#include "Color.hpp"
#include "Keys.hpp"
#include "Camera.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

namespace kdr
{
  /**
   * @brief Class representing a window.
   */
  class Window
  {
    public:
      /**
       * @brief Constructs a window with specified width, height, and title.
       *
       * @param width The width of the window.
       * @param height The height of the window.
       * @param title The title of the window.
       */
      Window(const unsigned int width, const unsigned int height, const std::string& title)
      : width(width), height(height), title(title)
      { this->_initialize(); }
      /**
       * @brief Destructor for the Window class.
       *
       * Cleans up GLFW resources associated with the window.
       */
      virtual ~Window()
      {
        glfwDestroyWindow(this->glfwWindow);
      }

      /**
       * @brief Main loop function for the window.
       */
      void loop();
      /**
       * @brief Closes the window.
       */
      void close()
      { glfwSetWindowShouldClose(this->glfwWindow, GLFW_TRUE); }

      /**
       * @brief Gets the GLFW window associated with this object.
       * 
       * @return A pointer to the GLFW window.
       */
      GLFWwindow* getGlfwWindow() const
      { return this->glfwWindow; }
      /**
       * @brief Gets the width of the window.
       *
       * @return The width of the window.
       */
      unsigned int getWidth() const
      { return this->width; }
      /**
       * @brief Gets the height of the window.
       *
       * @return The height of the window.
       */
      unsigned int getHeight() const
      { return this->height; }
      /**
       * @brief Gets the title of the window.
       *
       * @return The title of the window.
       */
      std::string getTitle() const
      { return this->title; }
      /**
       * @brief Gets the delta time.
       *
       * This function returns the delta time for the window.
       *
       * @return The delta time.
       */
      float getDeltaTime() const
      { return this->deltaTime; }
      /**
       * @brief Gets the ID of the shader bound to the window.
       *
       * @return The ID of the bound shader.
       */
      GLuint getBoundShaderID() const
      { return this->boundShaderID; }
      /**
       * @brief Gets the camera bound to the window.
       *
       * @return A pointer to the bound camera.
       */
      kdr::Camera* getBoundCamera() const
      { return this->boundCamera; }

      /**
       * @brief Sets the ID of the shader bound to the window.
       * 
       * @param shaderID The ID of the shader program to bind to the window.
       */
      void setBoundShaderID(const GLuint shaderID)
      { this->boundShaderID = shaderID; }
      /**
       * @brief Sets the camera bound to the window.
       * 
       * @param camera A pointer to the camera object to bind to the window.
       */
      void setBoundCamera(kdr::Camera* camera)
      { this->boundCamera = camera; }

      /**
       * Sets the clear color for the window.
       * 
       * @param color The color to set as the clear color.
       */
      void setClearColor(const kdr::Color::RGBA& color)
      {
        this->clearColor = color;
        glClearColor(
          color.red,
          color.green,
          color.blue,
          color.alpha
        );
      }

    protected:
      /**
       * @brief Virtual function to update the window state.
       */
      virtual void update() = 0;
      /**
       * @brief Virtual function to render the window contents.
       */
      virtual void render() = 0;

    private:
      unsigned int width  {800};
      unsigned int height {600};
      std::string  title  {"GLFW"};

      GLFWwindow*      glfwWindow {NULL};
      kdr::Color::RGBA clearColor {kdr::Color::Black};

      float deltaTime {0.f};
      float lastTime  {(float)glfwGetTime()};

      GLuint       boundShaderID   {0};
      kdr::Camera* boundCamera     {NULL};
      kdr::Key     cameraBindKey   {kdr::Key::E};
      kdr::Key     cameraUnbindKey {kdr::Key::Escape};

      /**
       * @brief Initializes the window.
       * 
       * This function initializes the GLFW window and OpenGL settings.
       * 
       * @return True if initialization is successful, false otherwise.
       */
      bool _initializeWindow();
      /**
       * @brief Initializes OpenGL settings.
       * 
       * This function initializes OpenGL settings.
       * 
       * @return True if initialization is successful, false otherwise.
       */
      bool _initializeOpenGLSettings();
      /**
       * @brief Initializes the window and OpenGL settings.
       * 
       * This function initializes both the GLFW window and OpenGL settings.
       * 
       * @return True if initialization is successful, false otherwise.
       */
      bool _initialize();
      /**
       * @brief Updates the delta time.
       *
       * This function updates the delta time for the window.
       */
      void _updateDeltaTime();
      /**
       * @brief Updates the camera state.
       * 
       * This function updates the state of the camera bound to the window.
       */
      void _updateCamera();
      /**
       * @brief Updates the window state.
       */
      void _update();
      /**
       * @brief Renders the window contents.
       */
      void _render();
  };
}

#endif // KDR_WINDOW_HPP
