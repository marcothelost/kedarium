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
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
    Escape = GLFW_KEY_ESCAPE,
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
