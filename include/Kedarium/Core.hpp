#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Constants.hpp"

namespace kdr
{
  /**
   * Namespace containing core functionality of the Kedarium Engine.
   */
  namespace Core
  {
    /**
     * @brief Prints information about the Kedarium Engine.
     */
    void printEngineInfo();
    /**
     * @brief Prints version information of the Kedarium Engine.
     * 
     * This function requires OpenGL, GLEW, and GLFW libraries.
     */
    void printVersionInfo();
  }
}

#endif // KDR_CORE_HPP
