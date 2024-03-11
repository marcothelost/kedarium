#ifndef KDR_IMAGE_HPP
#define KDR_IMAGE_HPP

#include <GL/glew.h>
#include <png.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

namespace kdr
{
  /**
   * @brief Namespace containing image-related functionality.
   */
  namespace Image
  {
    /**
     * @brief Loads image data from a PNG file.
     * 
     * @param path The file path to the PNG image.
     * @param oData Pointer to store the image data.
     * @param oWidth Output parameter to store the width of the image.
     * @param oHeight Output parameter to store the height of the image.
     * @param oHasAlpha Output parameter indicating if the image has an alpha channel.
     * @return True if the image is loaded successfully, false otherwise.
     */
    bool loadFromPNG(const std::string& path, GLubyte** oData, int& oWidth, int& oHeight, bool& oHasAlpha);
  }
}

#endif // KDR_IMAGE_HPP
