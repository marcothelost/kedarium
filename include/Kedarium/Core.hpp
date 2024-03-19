#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <map>
#include <string>

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

    /**
     * @brief A generic manager class for storing and retrieving items by key.
     * 
     * @tparam T The type of items stored in the manager.
     */
    template<class T>
    class Manager
    {
      public:
        /**
         * @brief Adds an item to the manager with the specified key.
         * 
         * @param key The key associated with the item.
         * @param value The value of the item to add.
         */
        void add(const std::string& key, const T& value)
        {
          this->items[key] = value;
        }

        /**
         * @brief Retrieves an item from the manager by its key.
         * 
         * If the item with the specified key is found, it is returned.
         * If the item is not found, a default value of type T is returned and an error message is printed.
         * 
         * @param key The key of the item to retrieve.
         * @return A reference to the retrieved item.
         */
        T& get(const std::string& key)
        {
          auto it = items.find(key);
          if (it != items.end())
          {
            return it->second;
          }
          std::cerr << "Item with key \"" << key << "\" not found!\n";
          static T default_value;
          return default_value;
        }

        /**
         * @brief Clears all items stored in the manager.
         */
        void clear()
        {
          this->items.clear();
        }

      private:
        std::map<std::string, T> items;
    };
  }
}

#endif // KDR_CORE_HPP
