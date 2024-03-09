#ifndef KDR_KEYS_HPP
#define KDR_KEYS_HPP

#include <GLFW/glfw3.h>

namespace kdr
{
  /**
   * @brief Enumeration of keys with GLFW key codes.
   */
  enum Key
  {
    W = GLFW_KEY_W,
    S = GLFW_KEY_S,
    A = GLFW_KEY_A,
    D = GLFW_KEY_D,
    Spacebar = GLFW_KEY_SPACE,
    LeftShift = GLFW_KEY_LEFT_SHIFT,
 };

  /**
   * @brief Namespace containing functions related to keyboard input.
   */
  namespace Keys
  {
    /**
     * @brief Checks if a specific key is currently pressed.
     * 
     * @param window The GLFW window to query.
     * @param key The key to check.
     * @return True if the key is currently pressed, false otherwise.
     */
    inline bool isPressed(GLFWwindow* window, const kdr::Key& key)
    { return glfwGetKey(window, key) == GLFW_PRESS; }
  }
}

#endif // KDR_KEYS_HPP
