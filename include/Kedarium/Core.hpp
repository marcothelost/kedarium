#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include <memory>
#include <iostream>
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
     * @brief A template class for managing objects by key.
     * 
     * @tparam T The type of items to manage.
     */
    template <typename T>
    class Manager
    {
      public:
        /**
         * @brief Adds an item to the manager.
         * 
         * @param key The key associated with the item.
         * @param item The item to add.
         */
        void add(std::string key, const T& item)
        {
          this->items[key] = std::make_unique<T>(item);
        }
        /**
         * @brief Gets an item from the manager.
         * 
         * @param key The key associated with the item to retrieve.
         * @return A pointer to the item if found, nullptr otherwise.
         */
        T* get(std::string key)
        {
          auto it = this->items.find(key);
          if (it == this->items.end())
          {
            std::cerr << "Item \"" << key << "\" not found!\n";
            return NULL;
          }
          return (it->second).get();
        }
        /**
         * @brief Removes an item from the manager.
         * 
         * @param key The key associated with the item to remove.
         */
        void remove(std::string key)
        {
          this->items.erase(key);
        }
        /**
         * @brief Clears all items from the manager.
         */
        void clear()
        { this->items.clear(); }

      private:
        std::map<std::string, std::unique_ptr<T>> items;
    };
  }
}

#endif // KDR_CORE_HPP
