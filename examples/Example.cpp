#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Space.hpp"
#include "Kedarium/Keys.hpp"
#include "Kedarium/Camera.hpp"
#include "Kedarium/Solids.hpp"
#include "Kedarium/Lights.hpp"
#include "Kedarium/GUI.hpp"
#include "Kedarium/Debug.hpp"

// Window Settings
constexpr unsigned int WINDOW_WIDTH  {800};
constexpr unsigned int WINDOW_HEIGHT {600};
const     std::string  WINDOW_TITLE  {"GLFW"};

// Camera Settings
constexpr float CAMERA_FOV         {60.f};
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

    void initialize()
    {
      this->addShader("default", "assets/Shaders/default.vert", "assets/Shaders/default.frag");
      this->addShader("gui", "assets/Shaders/gui.vert", "assets/Shaders/gui.frag");

      this->addTexture("nathan", "assets/Textures/nathan.png");
      this->addTexture("stove", "assets/Textures/stove.png");
      this->addTexture("floor", "assets/Textures/tiles.png");
      this->addTexture("tiles", "assets/Textures/marble_tiles.png");
      this->addTexture("crosshair", "assets/Textures/crosshair.png");

      this->lights.push_back(kdr::Lights::Light(
        {-3.f, 2.f, 3.f},
        kdr::Color::Magenta,
        2.5f
      ));
      this->lights.push_back(kdr::Lights::Light(
        {3.f, 2.f, 3.f},
        kdr::Color::Cyan,
        1.5f
      ));
      this->lights.push_back(kdr::Lights::Light(
        {-3.f, 2.f, -3.f},
        kdr::Color::Yellow,
        1.5f
      ));
      this->lights.push_back(kdr::Lights::Light(
        {3.f, 2.f, -3.f},
        kdr::Color::Green,
        1.5f
      ));

      this->bindShader("default");
      this->useLights(this->lights);

      this->stove.rotateY(180.f);
    }

    void onResize()
    {
      this->crosshair.update({
        (float)this->getWidth(),
        (float)this->getHeight()
      });
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
      this->bindShader("default");
      this->bindTexture("nathan");
      this->renderSolid(nathan);
      this->bindTexture("stove");
      this->renderSolid(stove);
      this->bindTexture("tiles");
      this->renderSolid(wall);
      this->bindTexture("floor");
      this->renderSolid(plane);
      this->bindShader("gui");
      this->use2D();
      this->bindTexture("crosshair");
      this->renderElement(crosshair);
      this->bindShader("default");
    }

  private:
    kdr::GUI::Crosshair crosshair {
      {WINDOW_WIDTH, WINDOW_HEIGHT},
      16.f
    };
    kdr::Solids::Plane plane {
      {0.f, 0.f, 0.f},
      20.f,
      20.f
    };
    kdr::Solids::Mesh nathan {
      {0.f, 0.f, 0.f},
      "assets/Objects/nathan.obj"
    };
    kdr::Solids::Mesh stove {
      {0.f, 0.f, 1.f},
      "assets/Objects/stove.obj"
    };
    kdr::Solids::Cuboid wall {
      {0.f, 1.5f, -0.6f},
      6.f,
      3.f,
      0.2f
    };

    std::vector<kdr::Lights::Light> lights;
};

int main()
{
  // Initializing GLFW
  kdr::Core::initializeGlfw();

  // Camera
  kdr::Camera camera {
    {0.f, 1.f, 3.f},
    CAMERA_FOV,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
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
  window.bindCamera(&camera);

  // Initializing the Window
  window.initialize();

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
