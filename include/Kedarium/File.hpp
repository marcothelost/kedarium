#ifndef KDR_FILE_HPP
#define KDR_FILE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

namespace kdr
{
  /**
   * @brief Namespace containing file-related functionality.
   */
  namespace File
  {
    /**
     * @brief Reads the contents of a file and returns it as a string.
     *
     * @param path The path to the file.
     * @return The contents of the file as a string, or an empty string if the file cannot be loaded.
     */
    std::string getContents(const std::string& path);
  }
}

#endif // KDR_FILE_HPP
