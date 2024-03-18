#include <stdio.h>
#include <string>

#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"

constexpr unsigned int WINDOW_WIDTH  {800};
constexpr unsigned int WINDOW_HEIGHT {600};
const     std::string  WINDOW_TITLE  {"Solar System"};

class MainWindow : public kdr::Window
{
  public:
    using kdr::Window::Window;

  protected:
    void update()
    {
      
    }

    void render()
    {
      this->bindShader(&defaultShader);
    }

  private:
    kdr::Graphics::Shader defaultShader {
      "assets/Shaders/default.vert",
      "assets/Shaders/default.frag"
    };
};

int main()
{
  kdr::Core::initializeGlfw();

  MainWindow window {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };

  window.loop();
  window.close();

  return EXIT_SUCCESS;
}
