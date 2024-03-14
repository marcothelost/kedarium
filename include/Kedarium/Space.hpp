#ifndef KDR_SPACE_HPP
#define KDR_SPACE_HPP

#include <cmath>

namespace kdr
{
  /**
   * @brief Namespace containing space-related functionality.
   */
  namespace Space
  {
    /**
     * @brief Constant representing the value of Pi.
     */
    inline const float PI = 3.141593f;

    /**
     * @brief Converts degrees to radians.
     * 
     * @param degrees The angle in degrees.
     * @return The angle in radians.
     */
    inline float radians(const float degrees)
    {
      return degrees * (kdr::Space::PI / 180.f);
    }

    /**
     * @brief Class representing a 2D vector.
     */
    class Vec2
    {
      public:
        /**
         * @brief Default constructor. Initializes vector components to zero.
         */
        Vec2()
        : x(0.f), y(0.f)
        {}
        /**
         * @brief Constructor initializing all components with a scalar value.
         *
         * @param scalar The value to set for all components.
         */
        Vec2(const float scalar)
        : x(scalar), y(scalar)
        {}
        /**
         * @brief Constructor initializing components with specific values.
         *
         * @param x The x-component.
         * @param y The y-component.
         */
        Vec2(const float x, const float y)
        : x(x), y(y)
        {}

        /**
         * @brief Overloaded addition operator for adding two 2D vectors.
         * 
         * @param vec The vector to add.
         * @return The result of the addition.
         */
        kdr::Space::Vec2 operator+(const kdr::Space::Vec2& vec) const
        {
          return kdr::Space::Vec2(
            this->x + vec.x,
            this->y + vec.y
          );
        }
        /**
         * @brief Overloaded subtraction operator for subtracting two 2D vectors.
         * 
         * @param vec The vector to subtract.
         * @return The result of the subtraction.
         */
        kdr::Space::Vec2 operator-(const kdr::Space::Vec2& vec) const
        {
          return kdr::Space::Vec2(
            this->x - vec.x,
            this->y - vec.y
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
        kdr::Space::Vec2 operator*(const T scalar)
        {
          return kdr::Space::Vec2(
            static_cast<float>(this->x * scalar),
            static_cast<float>(this->y * scalar)
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
        friend kdr::Space::Vec2 operator*(const T scalar, const kdr::Space::Vec2& vec)
        {
          return kdr::Space::Vec2(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar)
          );
        }

        /**
         * @brief Adds the components of the given vector to this vector.
         * 
         * @param vec The vector to add.
         * @return The resulting vector after addition.
         */
        kdr::Space::Vec2 operator+=(const kdr::Space::Vec2& vec)
        {
          this->x += vec.x;
          this->y += vec.y;
          return *this;
        }
        /**
         * @brief Subtracts the components of the given vector from this vector.
         * 
         * @param vec The vector to subtract.
         * @return The resulting vector after subtraction.
         */
        kdr::Space::Vec2 operator-=(const kdr::Space::Vec2& vec)
        {
          this->x -= vec.x;
          this->y -= vec.y;
          return *this;
        }

        float x {0.f};
        float y {0.f};
    };

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
        kdr::Space::Vec3 operator+(const kdr::Space::Vec3& vec) const
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
        kdr::Space::Vec3 operator-(const kdr::Space::Vec3& vec) const
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
        kdr::Space::Vec3 operator*(const T scalar)
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
        friend kdr::Space::Vec3 operator*(const T scalar, const kdr::Space::Vec3& vec)
        {
          return kdr::Space::Vec3(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar),
            static_cast<float>(vec.z * scalar)
          );
        }

        /**
         * @brief Adds the components of the given vector to this vector.
         * 
         * @param vec The vector to add.
         * @return The resulting vector after addition.
         */
        kdr::Space::Vec3 operator+=(const kdr::Space::Vec3& vec)
        {
          this->x += vec.x;
          this->y += vec.y;
          this->z += vec.z;
          return *this;
        }
        /**
         * @brief Subtracts the components of the given vector from this vector.
         * 
         * @param vec The vector to subtract.
         * @return The resulting vector after subtraction.
         */
        kdr::Space::Vec3 operator-=(const kdr::Space::Vec3& vec)
        {
          this->x -= vec.x;
          this->y -= vec.y;
          this->z -= vec.z;
          return *this;
        }

        float x {0.f};
        float y {0.f};
        float z {0.f};
    };

    /**
     * @brief Normalizes the given vector.
     * 
     * @param vec The vector to normalize.
     * @return The normalized vector.
     */
    inline kdr::Space::Vec2 normalize(const kdr::Space::Vec2& vec)
    {
      const float length = sqrtf(vec.x * vec.x + vec.y * vec.y);
      if (length == 0.f) return kdr::Space::Vec2 {0.f};

      return kdr::Space::Vec2 {
        vec.x / length,
        vec.y / length
      };
    }
    /**
     * @brief Normalizes the given vector.
     * 
     * @param vec The vector to normalize.
     * @return The normalized vector.
     */
    inline kdr::Space::Vec3 normalize(const kdr::Space::Vec3& vec)
    {
      const float length = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
      if (length == 0.f) return kdr::Space::Vec3 {0.f};

      return kdr::Space::Vec3 {
        vec.x / length,
        vec.y / length,
        vec.z / length
      };
    }
    /**
     * @brief Computes the dot product of two 3D vectors.
     * 
     * @param vecOne The first vector.
     * @param vecTwo The second vector.
     * @return The dot product of the two vectors.
     */
    inline float dot(const kdr::Space::Vec3& vecOne, const kdr::Space::Vec3& vecTwo)
    {
      return vecOne.x * vecTwo.x + vecOne.y * vecTwo.y + vecOne.z * vecTwo.z;
    }
    /**
     * @brief Computes the dot product of two 2D vectors.
     * 
     * @param vecOne The first vector.
     * @param vecTwo The second vector.
     * @return The dot product of the two vectors.
     */
    inline float dot(const kdr::Space::Vec2& vecOne, const kdr::Space::Vec2& vecTwo)
    {
      return vecOne.x * vecTwo.x + vecOne.y * vecTwo.y;
    }
    /**
     * @brief Computes the cross product of two 3D vectors.
     * 
     * @param vecOne The first vector.
     * @param vecTwo The second vector.
     * @return The cross product of the two vectors.
     */
    inline kdr::Space::Vec3 cross(const kdr::Space::Vec3& vecOne, const kdr::Space::Vec3& vecTwo)
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

        /**
         * @brief Multiplies this matrix by another matrix.
         * 
         * @param mat The matrix to multiply by.
         * @return The result of the matrix multiplication.
         */
        kdr::Space::Mat4 operator*(const kdr::Space::Mat4& mat) const
        {
          kdr::Space::Mat4 result;
          for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
              for (int k = 0; k < 4; k++) {
                result[i][j] += mat[i][k] * this->elements[k][j];
              }
            }
          }
          return result;
        }

      private:
        float elements[4][4];
    };

    /**
     * @brief Applies translation to a 4x4 matrix.
     * 
     * This function translates the given matrix by the specified vector.
     * 
     * @param mat The matrix to translate.
     * @param vec The translation vector.
     * @return The translated matrix.
     */
    inline kdr::Space::Mat4 translate(const kdr::Space::Mat4& mat, const kdr::Space::Vec3& vec)
    {
      kdr::Space::Mat4 result {mat};
      result[3][0] += vec.x;
      result[3][1] += vec.y;
      result[3][2] += vec.z;
      return result;
    }
    /**
     * @brief Applies rotation to a 4x4 matrix.
     * 
     * This function rotates the given matrix by the specified angle around the specified axis.
     * 
     * @param mat The matrix to rotate.
     * @param angle The angle of rotation in degrees.
     * @param axes The axis of rotation.
     * @return The rotated matrix.
     */
    kdr::Space::Mat4 rotate(const kdr::Space::Mat4& mat, const float angle, const kdr::Space::Vec3& axes);
    /**
     * @brief Creates an orthographic projection matrix.
     * 
     * @param left The left coordinate of the projection volume.
     * @param right The right coordinate of the projection volume.
     * @param bottom The bottom coordinate of the projection volume.
     * @param top The top coordinate of the projection volume.
     * @param zNear The near clipping plane distance.
     * @param zFar The far clipping plane distance.
     * @return The orthographic projection matrix.
     */
    kdr::Space::Mat4 ortho(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar);
    /**
     * @brief Creates a perspective projection matrix.
     * 
     * @param fov The field of view angle in degrees.
     * @param aspect The aspect ratio of the projection (width / height).
     * @param zNear The near clipping plane.
     * @param zFar The far clipping plane.
     * @return The perspective projection matrix.
     */
    kdr::Space::Mat4 perspective(const float fov, const float aspect, const float zNear, const float zFar);
    /**
     * @brief Creates a view matrix for a camera positioned at the given eye point, looking towards the target point, with the given up direction.
     * 
     * @param eye The position of the camera.
     * @param target The point the camera is looking at.
     * @param up The up direction of the camera.
     * @return The view matrix.
     */
    kdr::Space::Mat4 lookAt(const kdr::Space::Vec3& eye, const kdr::Space::Vec3& target, const kdr::Space::Vec3& up);

    /**
     * @brief Returns a pointer to the underlying array storing the elements of a 4x4 matrix.
     * 
     * @param mat The matrix.
     * @return A pointer to the first element of the matrix.
     */
    inline const float* valuePointer(const kdr::Space::Mat4& mat)
    {
      return &mat[0][0];
    }
  }
}

#endif // KDR_SPACE_HPP
