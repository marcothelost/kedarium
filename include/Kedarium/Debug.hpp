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
  }
}

#endif // KDR_DEBUG_HPP
