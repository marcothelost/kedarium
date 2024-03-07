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

    /**
     * @brief Initializes GLFW.
     *
     * @return True if GLFW initialization is successful, false otherwise.
     */
    bool initializeGlfw();
    /**
     * @brief Initializes GLEW.
     *
     * @return True if GLEW initialization is successful, false otherwise.
     */
    bool initializeGlew();
    /**
     * @brief Terminates GLFW.
     */
    void terminate();
  }
}

#endif // KDR_CORE_HPP
