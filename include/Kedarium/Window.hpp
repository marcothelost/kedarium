#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>

#include "Core.hpp"
#include "Graphics.hpp"
#include "Color.hpp"
#include "Keys.hpp"
#include "Camera.hpp"
#include "Solids.hpp"
#include "Lights.hpp"
#include "GUI.hpp"

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
       * @brief Gets the shader currently bound to the window.
       *
       * @return A pointer to the bound shader.
       */
      kdr::Graphics::Shader* getBoundShader() const
      { return this->boundShader; }
      /**
       * @brief Gets the camera bound to the window.
       *
       * @return A pointer to the bound camera.
       */
      kdr::Camera* getBoundCamera() const
      { return this->boundCamera; }

      /**
       * @brief Sets the width of the window.
       * 
       * @param width The new width of the window.
       */
      void setWidth(const float width)
      { this->width = width; }
      /**
       * @brief Sets the height of the window.
       * 
       * @param height The new height of the window.
       */
      void setHeight(const float height)
      { this->height = height; }
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

      /**
       * @brief Virtual function called when the window is resized.
       */
      virtual void onResize()
      {}

      /**
       * @brief Maximizes the window.
       */
      void maximize();
      /**
       * @brief Unmaximizes the window.
       */
      void unmaximize();
      /**
       * @brief Switches the rendering mode to 2D.
       */
      void use2D()
      {
        if (this->boundCamera == NULL || this->boundShader == NULL) return;
        this->boundCamera->updateMatrix2D();
        this->boundCamera->applyMatrix(this->boundShader->getID(), "cameraMatrix");
      }
      /**
       * @brief Switches the rendering mode to 3D.
       */
      void use3D()
      {
        if (this->boundCamera == NULL || this->boundShader == NULL) return;
        this->boundCamera->updateMatrix3D();
        this->boundCamera->applyMatrix(this->boundShader->getID(), "cameraMatrix");
      }

      /**
       * @brief Binds a shader to the window.
       * 
       * @param shader A pointer to the shader object to bind.
       */
      void bindShader(kdr::Graphics::Shader* shader)
      {
        this->boundShader = shader;
        shader->Use();
      }
      /**
       * @brief Binds a texture to the window.
       * 
       * @param texture The texture object to bind.
       */
      void bindTexture(const kdr::Graphics::Texture& texture)
      {
        if (this->boundShader == NULL)
        {
          return;
        }
        texture.TextureUnit(this->boundShader->getID(), "tex0", 0);
        texture.Bind();
      }
      /**
       * @brief Binds a camera to the window.
       * 
       * @param camera A pointer to the camera object to bind.
       */
      void bindCamera(kdr::Camera* camera)
      {
        this->boundCamera = camera;
      }
      /**
       * @brief Renders a solid object.
       * 
       * @param solid The solid object to render.
       */
      void renderSolid(const kdr::Solids::Solid& solid)
      {
        if (this->boundShader == NULL)
        {
          return;
        }
        solid.applyModelMatrix(this->boundShader->getID(), "model");
        solid.render();
      }
      /**
       * @brief Renders a GUI element.
       * 
       * @param element The GUI element to render.
       */
      void renderElement(const kdr::GUI::Element& element)
      {
        if (this->boundShader == NULL)
        {
          return;
        }
        element.applyPosition(this->boundShader->getID(), "position");
        element.render();
      }
      /**
       * @brief Applies multiple lights to the currently bound shader program.
       * 
       * @param lights A vector containing the lights to apply.
       */
      void useLights(std::vector<kdr::Lights::Light>& lights)
      {
        if (this->boundShader == NULL)
        {
          return;
        }
        int index = 0;
        for (kdr::Lights::Light& light : lights)
        {
          light.apply(this->boundShader->getID(), index, "lightPos", "lightCol");
          index++;
        }
        this->boundShader->setVector3("camPos", this->getBoundCamera()->getPosition()); 
        this->boundShader->setInt("lightCount", lights.size()); 
      }

    protected:
      /**
       * @brief Virtual function to update the window state.
       */
      virtual void update()
      {}
      /**
       * @brief Virtual function to render the window contents.
       */
      virtual void render()
      {}

    private:
      unsigned int width  {800};
      unsigned int height {600};
      std::string  title  {"GLFW"};

      GLFWwindow*      glfwWindow {NULL};
      kdr::Color::RGBA clearColor {kdr::Color::Black};

      float deltaTime {0.f};
      float lastTime  {(float)glfwGetTime()};

      kdr::Graphics::Shader* boundShader     {0};
      kdr::Camera*           boundCamera     {NULL};
      kdr::Key               cameraBindKey   {kdr::Key::E};
      kdr::Key               cameraUnbindKey {kdr::Key::Escape};

      kdr::Key fullscreenKey     {kdr::Key::F};
      bool     fullscreenEnabled {false};
      bool     canUseFullscreen  {true};

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
