#ifndef KDR_COLOR_HPP
#define KDR_COLOR_HPP

#include <stdint.h>

namespace kdr
{
  /**
   * Namespace containing color-related functionality.
   */
  namespace Color
  {
    /**
     * Struct representing a color in RGBA format.
     */
    struct RGBA
    {
      float red;
      float green;
      float blue;
      float alpha;

       /**
       * Constructor for RGBA struct.
       *
       * @param red Red component of the color (0-255).
       * @param green Green component of the color (0-255).
       * @param blue Blue component of the color (0-255).
       * @param alpha Alpha (transparency) component of the color (0-1).
       */
      RGBA(const uint8_t red, const uint8_t green, const uint8_t blue, const float alpha)
      : red(red / 255.f), green(green / 255.f), blue(blue / 255.f), alpha(alpha)
      {}
    };

    /**
     * RGBA color constant representing white.
     */
    inline const kdr::Color::RGBA White {255, 255, 255, 1.f};
    /**
     * RGBA color constant representing black.
     */
    inline const kdr::Color::RGBA Black {0, 0, 0, 1.f};
    /**
     * RGBA color constant representing red.
     */
    inline const kdr::Color::RGBA Red {255, 0, 0, 1.f};
    /**
     * RGBA color constant representing green.
     */
    inline const kdr::Color::RGBA Green {0, 255, 0, 1.f};
    /**
     * RGBA color constant representing blue.
     */
    inline const kdr::Color::RGBA Blue {0, 0, 255, 1.f};
    /**
     * RGBA color constant representing yellow.
     */
    inline const kdr::Color::RGBA Yellow {255, 255, 0, 1.f};
    /**
     * RGBA color constant representing cyan.
     */
    inline const kdr::Color::RGBA Cyan {0, 255, 255, 1.f};
    /**
     * RGBA color constant representing magenta.
     */
    inline const kdr::Color::RGBA Magenta {255, 0, 255, 1.f};
  }
}

#endif // KDR_COLOR_HPP
