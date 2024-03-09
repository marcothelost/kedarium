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

        /**
         * @brief Overloaded addition operator for adding two 3D vectors.
         * 
         * @param vec The vector to add.
         * @return The result of the addition.
         */
        Vec3 operator+(const kdr::Space::Vec3& vec) const
        {
          return kdr::Space::Vec3(
            this->x + vec.x,
            this->y + vec.y,
            this->z + vec.z
          );
        }
        /**
         * @brief Overloaded subtraction operator for subtracting two 3D vectors.
         * 
         * @param vec The vector to subtract.
         * @return The result of the subtraction.
         */
        Vec3 operator-(const kdr::Space::Vec3& vec) const
        {
          return kdr::Space::Vec3(
            this->x - vec.x,
            this->y - vec.y,
            this->z - vec.z
          );
        }
        /**
         * @brief Overloaded multiplication operator for multiplying a vector by a scalar.
         * 
         * @tparam T The scalar type.
         * @param scalar The scalar value to multiply.
         * @return The result of the multiplication.
         */
        template <typename T>
        Vec3 operator*(const T scalar)
        {
          return kdr::Space::Vec3(
            static_cast<float>(this->x * scalar),
            static_cast<float>(this->y * scalar),
            static_cast<float>(this->z * scalar)
          );
        }
        /**
         * @brief Overloaded multiplication operator for multiplying a scalar by a vector.
         * 
         * @tparam T The scalar type.
         * @param scalar The scalar value to multiply.
         * @param vec The vector to multiply.
         * @return The result of the multiplication.
         */
        template <typename T>
        friend Vec3 operator*(const T scalar, const kdr::Space::Vec3& vec)
        {
          return kdr::Space::Vec3(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar),
            static_cast<float>(vec.z * scalar)
          );
        }

        float x {0.f};
        float y {0.f};
        float z {0.f};
    };

    /**
     * @brief Computes the dot product of two 3D vectors.
     * 
     * @param vecOne The first vector.
     * @param vecTwo The second vector.
     * @return The dot product of the two vectors.
     */
    float dot(const kdr::Space::Vec3& vecOne, const kdr::Space::Vec3& vecTwo)
    {
      return vecOne.x * vecTwo.x + vecOne.y * vecTwo.y + vecOne.z * vecTwo.z;
    }
    /**
     * @brief Computes the cross product of two 3D vectors.
     * 
     * @param vecOne The first vector.
     * @param vecTwo The second vector.
     * @return The cross product of the two vectors.
     */
    kdr::Space::Vec3 cross(const kdr::Space::Vec3& vecOne, const kdr::Space::Vec3& vecTwo)
    {
      return kdr::Space::Vec3 {
        vecOne.y * vecTwo.z - vecOne.z * vecTwo.y,
        vecOne.z * vecTwo.x - vecOne.x * vecTwo.z,
        vecOne.x * vecTwo.y - vecOne.y * vecTwo.x
      };
    }

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
