#ifndef KDR_SPACE_HPP
#define KDR_SPACE_HPP

namespace kdr
{
  /**
   * @brief Namespace containing space-related functionality.
   */
  namespace Space
  {
    /**
     * @brief Class representing a 3D vector.
     */
    class Vec3
    {
      public:
        /**
         * @brief Default constructor. Initializes vector components to zero.
         */
        Vec3()
        : x(0.f), y(0.f), z(0.f)
        {}
        /**
         * @brief Constructor initializing all components with a scalar value.
         *
         * @param scalar The value to set for all components.
         */
        Vec3(const float scalar)
        : x(scalar), y(scalar), z(scalar)
        {}
        /**
         * @brief Constructor initializing components with specific values.
         *
         * @param x The x-component.
         * @param y The y-component.
         * @param z The z-component.
         */
        Vec3(const float x, const float y, const float z)
        : x(x), y(y), z(z)
        {}

        float x {0.f};
        float y {0.f};
        float z {0.f};
    };
  }
}

#endif // KDR_SPACE_HPP
