#ifndef KDR_IMAGE_HPP
#define KDR_IMAGE_HPP

#include <png.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

namespace kdr
{
  namespace Image
  {
    bool loadFromPNG(const std::string& path, char** data, int& oWidth, int& oHeight);
  }
}

#endif // KDR_IMAGE_HPP
