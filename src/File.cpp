#include "Kedarium/File.hpp"

std::string kdr::File::getContents(const std::string& path)
{
  std::ifstream file(path);
  if (!file.is_open())
  {
    std::cerr << "Failed to open file (\"" << path << "\")!" << '\n';
    return "";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}
