#ifndef KDR_DEBUG_HPP
#define KDR_DEBUG_HPP

#include <iostream>

#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Namespace containing debugging functionality.
   */
  namespace Debug
  {
    /**
     * @brief Prints the components of a 3D vector.
     * 
     * @param vec The vector to print.
     */
    inline void printVector(const kdr::Space::Vec3& vec)
    {
      std::cout << "X: " << vec.x << "; Y: " << vec.y << "; Z: " << vec.z << '\n';
    }
    /**
     * @brief Prints the elements of a 4x4 matrix.
     * 
     * @param mat The matrix to print.
     */
    inline void printMatrix(const kdr::Space::Mat4& mat)
    {
      for (int y = 0; y < 4; y++)
      {
        for (int x = 0; x < 4; x++)
        {
          std::cout << mat[y][x] << ' ';
        }
        std::cout << '\n';
      }
    }
  }
}

#endif // KDR_DEBUG_HPP
