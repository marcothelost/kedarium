#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Core.hpp"

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

      GLFWwindow* glfwWindow {NULL};

      /**
       * @brief Initializes the GLFW window.
       *
       * @return True if initialization is successful, false otherwise.
       */
      bool _initialize();
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
