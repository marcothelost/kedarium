#include "Kedarium/Image.hpp"

bool kdr::Image::loadFromPNG(const std::string& path, char** data, int& oWidth, int& oHeight)
{
  png_structp  pngPtr;
  png_infop    infoPtr;
  unsigned int sigRead {0};
  int          colorType;
  int          interlaceType;
  FILE         *file;

  file = fopen(path.c_str(), "rb");
  if (file == NULL)
  {
    std::cerr << "Failed to open image (\"" << path << "\")!" << '\n';
    return false;
  }

  pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (pngPtr == NULL)
  {
     std::cerr << "Failed to created read struct for image (\"" << path << "\")!" << '\n';
    fclose(file);
    return false;
  }

  infoPtr = png_create_info_struct(pngPtr);
  if (infoPtr == NULL)
  {
    std::cerr << "Failed to created info struct for image (\"" << path << "\")!" << '\n';
    fclose(file);
    return false;
  }

  if (setjmp(png_jmpbuf(pngPtr)))
  {
    png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
    fclose(file);
    return false;
  }

  png_init_io(pngPtr, file);
  png_set_sig_bytes(pngPtr, sigRead);
  png_read_png(pngPtr, infoPtr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

  png_uint_32 width;
  png_uint_32 height;
  int         bitDepth;

  png_get_IHDR(pngPtr, infoPtr, &width, &height, &bitDepth, &colorType, &interlaceType, NULL, NULL);
  oWidth = width;
  oHeight = height;

  unsigned int rowBytes = png_get_rowbytes(pngPtr, infoPtr);
  *data = (char*)malloc(rowBytes * oHeight);

  png_bytepp rowPointers = png_get_rows(pngPtr, infoPtr);
  for (int i = 0; i < oHeight; i++)
  {
    memcpy(*data + (rowBytes * (oHeight - i - 1)), rowPointers[i], rowBytes);
  }

  png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
  fclose(file);
  return true;
}
