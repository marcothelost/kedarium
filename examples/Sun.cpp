#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Camera.hpp"
#include "Kedarium/Lights.hpp"
#include "Kedarium/GUI.hpp"

constexpr unsigned int WINDOW_WIDTH  {800};
constexpr unsigned int WINDOW_HEIGHT {600};
const     std::string  WINDOW_TITLE  {"Solar System"};

constexpr float CAMERA_FOV         {60.f};
constexpr float CAMERA_NEAR        {0.1f};
constexpr float CAMERA_FAR         {100.f};
constexpr float CAMERA_SPEED       {3.f};
constexpr float CAMERA_SENSITIVITY {0.1f};

class MainWindow : public kdr::Window
{
  public:
    using kdr::Window::Window;

    void initialize()
    {
      this->lights.push_back(kdr::Lights::Light(
        {0.f, -5.f, 0.f},
        kdr::Color::Yellow
      ));

      this->bindShader(&defaultShader);
      this->useLights(lights);
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
      this->bindTexture(sunTexture);
      this->renderSolid(sun);
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
    kdr::Graphics::Shader guiShader {
      "assets/Shaders/gui.vert",
      "assets/Shaders/gui.frag"
    };
    kdr::Graphics::Texture sunTexture {
      "assets/Textures/sun.png",
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
    kdr::Solids::Mesh sun {
      {0.f, 0.f, 0.f},
      "assets/Objects/sphere.obj"
    };
    kdr::GUI::Element crosshair {
      {(float)WINDOW_WIDTH / 2.f - 8.f, (float)WINDOW_HEIGHT / 2.f - 8.f},
      16.f,
      16.f
    };
    std::vector<kdr::Lights::Light> lights;
};

int main()
{
  kdr::Core::initializeGlfw();

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

  MainWindow window {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };
  window.bindCamera(&camera);
  window.initialize();

  kdr::Core::printEngineInfo();
  std::cout << '\n';
  kdr::Core::printVersionInfo();

  window.loop();

  kdr::Core::terminate();
  return EXIT_SUCCESS;
}
