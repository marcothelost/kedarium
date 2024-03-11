#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Space.hpp"
#include "Kedarium/Keys.hpp"
#include "Kedarium/Camera.hpp"
#include "Kedarium/Debug.hpp"

// Window Settings
constexpr unsigned int WINDOW_WIDTH  {800};
constexpr unsigned int WINDOW_HEIGHT {600};
const     std::string  WINDOW_TITLE  {"GLFW"};

// Camera Settings
constexpr float CAMERA_FOV         {60.f};
constexpr float CAMERA_ASPECT      {(float)WINDOW_WIDTH / WINDOW_HEIGHT};
constexpr float CAMERA_NEAR        {0.1f};
constexpr float CAMERA_FAR         {100.f};
constexpr float CAMERA_SPEED       {3.f};
constexpr float CAMERA_SENSITIVITY {10.f};

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.0f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
  -0.25f,  0.0f, 0.f, 1.f, 1.f, 1.f,
   0.25f,  0.0f, 0.f, 1.f, 1.f, 1.f,
   0.0f,   0.5f, 0.f, 1.f, 1.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

class ExampleWindow : public kdr::Window
{
  public:
    using kdr::Window::Window;

    ~ExampleWindow()
    {
      this->VAO1.Delete();
      this->VBO1.Delete();
      this->EBO1.Delete();
      this->defaultShader.Delete();
    }

    void initialize()
    {
      this->VAO1.Bind();
      this->VBO1.Bind();
      this->EBO1.Bind();

      this->VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
      this->VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

      this->VAO1.Unbind();
      this->VBO1.Unbind();
      this->EBO1.Unbind();
    }

  protected:
    void update()
    {
      if (this->getBoundCamera() == NULL || !this->getBoundCamera()->getLocked())
      {
        return;
      }

      if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::C))
      {
        kdr::Graphics::usePointMode();
      }
      else if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::V))
      {
        kdr::Graphics::useLineMode();
      }
      else if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::B))
      {
        kdr::Graphics::useFillMode();
      }
    }

    void render()
    {
      this->defaultShader.Use();
      this->setBoundShaderID(this->defaultShader.getID());
      this->VAO1.Bind();
      glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    }

  private:
    kdr::Graphics::Shader defaultShader
    {
      "assets/Shaders/default.vert",
      "assets/Shaders/default.frag"
    };

    kdr::Graphics::VAO VAO1;
    kdr::Graphics::VBO VBO1 {vertices, sizeof(vertices)};
    kdr::Graphics::EBO EBO1 {indices, sizeof(indices)};
};

int main()
{
  // Initializing GLFW
  kdr::Core::initializeGlfw();

  // Camera
  kdr::Camera camera {
    CAMERA_FOV,
    CAMERA_ASPECT,
    CAMERA_NEAR,
    CAMERA_FAR,
    CAMERA_SPEED,
    CAMERA_SENSITIVITY
  };

  // Window
  ExampleWindow window {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };
  window.setClearColor(kdr::Color::Black);
  window.setBoundCamera(&camera);

  // Initializing the Window
  window.initialize();

  // Clear Color
  kdr::Color::RGBA clearColor {kdr::Color::Black};

  // Info Logs
  kdr::Core::printEngineInfo();
  std::cout << '\n';
  kdr::Core::printVersionInfo();

  // Main Loop
  window.loop();

  // Termination
  kdr::Core::terminate();
  return EXIT_SUCCESS;
}
