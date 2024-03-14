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

    ~ExampleWindow()
    {
      this->defaultShader.Delete();
    }

    void initialize()
    {
      kdr::Lights::Light light {
        {0.f, 2.f, 3.f},
        kdr::Color::White
      };
      this->lights.push_back(light);
    }

    void onResize()
    {
      this->crosshair.setPosition({
        (float)this->getWidth() / 2.f - 8.f,
        (float)this->getHeight() / 2.f - 8.f
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
      this->bindShader(&defaultShader);
      this->useLights(lights);
      this->bindTexture(stoveTexture);
      this->renderSolid(object);
      this->bindTexture(marbleTexture);
      this->renderSolid(wall);
      this->bindTexture(floorTexture);
      this->renderSolid(plane);
      this->bindShader(&guiShader);
      this->use2D();
      this->bindTexture(crosshairTexture);
      this->renderElement(crosshair);
      this->bindShader(&defaultShader);
    }

  private:
    kdr::Graphics::Shader defaultShader {
      "assets/Shaders/default.vert",
      "assets/Shaders/default.frag"
    };
    kdr::Graphics::Shader guiShader {+
      "assets/Shaders/gui.vert",
      "assets/Shaders/gui.frag"
    };
    kdr::Graphics::Texture stoveTexture {
      "assets/Textures/stove.png",
      GL_TEXTURE_2D,
      GL_TEXTURE0,
      GL_UNSIGNED_BYTE
    };
    kdr::Graphics::Texture floorTexture {
      "assets/Textures/tiles.png",
      GL_TEXTURE_2D,
      GL_TEXTURE0,
      GL_UNSIGNED_BYTE
    };
    kdr::Graphics::Texture marbleTexture {
      "assets/Textures/marble_tiles.png",
      GL_TEXTURE_2D,
      GL_TEXTURE0,
      GL_UNSIGNED_BYTE
    };
    kdr::Graphics::Texture crosshairTexture {
      "assets/Textures/crosshair.png",
      GL_TEXTURE_2D,
      GL_TEXTURE0,
      GL_UNSIGNED_BYTE
    };
    kdr::GUI::Element crosshair {
      {(float)WINDOW_WIDTH / 2.f - 8.f, (float)WINDOW_HEIGHT / 2.f - 8.f},
      16.f,
      16.f
    };
    kdr::Solids::Plane plane {
      {0.f, 0.f, 0.f},
      20.f,
      20.f
    };
    kdr::Solids::Mesh object {
      {0.f, 0.f, 0.f},
      "assets/Objects/stove.obj"
    };
    kdr::Solids::Cuboid wall {
      {0.f, 1.5f, -0.5f},
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
