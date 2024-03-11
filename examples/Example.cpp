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
#include "Kedarium/Solids.hpp"

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
constexpr float CAMERA_SENSITIVITY {0.1f};

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
      this->defaultShader.Delete();
    }

    void initialize()
    {}

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
      this->cube.render();
    }

  private:
    kdr::Graphics::Shader defaultShader
    {
      "assets/Shaders/default.vert",
      "assets/Shaders/default.frag"
    };
    kdr::Solids::Cube cube {
      {0.f, 0.f, 0.f},
      1.f
    };
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
