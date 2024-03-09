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

    /**
     * @brief Class representing a 4x4 matrix.
     */
    class Mat4
    {
      public:
        /**
         * @brief Default constructor.
         *
         * Initializes all elements of the matrix to zero.
         */
        Mat4()
        {
          for (int y = 0; y < 4; y++)
          {
            for (int x = 0; x < 4; x++)
            {
              elements[y][x] = 0.f;
            }
          }
        }
        /**
         * @brief Constructor initializing the diagonal elements of the matrix with a specified value.
         *
         * @param diagonalValue The value to set for the diagonal elements.
         */
        Mat4(const float diagonalValue)
        {
          for (int y = 0; y < 4; y++)
          {
            for (int x = 0; x < 4; x++)
            {
              elements[y][x] = x == y ? diagonalValue : 0.f;
            }
          }
        }

        /**
         * @brief Overloaded subscript operator for accessing elements of the matrix.
         *
         * @param index The index of the row.
         * @return A pointer to the specified row of the matrix.
         */
        float* operator[](int index)
        { return this->elements[index]; }
        /**
         * @brief Overloaded const subscript operator for accessing elements of the matrix.
         *
         * @param index The index of the row.
         * @return A const pointer to the specified row of the matrix.
         */
        const float* operator[](int index) const
        { return this->elements[index]; }

      private:
        float elements[4][4];
    };
  }
}

#endif // KDR_SPACE_HPP
