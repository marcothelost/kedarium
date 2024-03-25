#include "Kedarium/Object.hpp"

bool kdr::Object::loadFromObj(const std::string& objPath, std::vector<GLfloat>& oVertices, GLsizeiptr& oVerticesSize, std::vector<GLuint>& oIndices, GLsizeiptr& oIndicesSize, const kdr::Space::Vec3& dimensions)
{
  std::ifstream file(objPath);
  if (!file.is_open())
  {
    std::cerr << "Failed to open object file (\"" << objPath << "\")!" << '\n';
    return false;
  }

  std::vector<float> vecVals;
  std::vector<float> texVals;
  std::vector<float> normVals;
  std::vector<int>   faceData;
  std::string        lineBuffer;

  float minX {0.f};
  float maxX {0.f};
  float minY {0.f};
  float maxY {0.f};
  float minZ {0.f};
  float maxZ {0.f};

  while (std::getline(file, lineBuffer))
  {
    if (lineBuffer.find("v ") == 0)
    {
      std::istringstream ss(lineBuffer);
      std::string prefix;
      float x, y, z;

      ss >> prefix >> x >> y >> z;
      if (ss.fail())
      {
        std::cerr << "Failed to parse line: " << lineBuffer << "!\n";
        ss.clear();
        continue;
      }

      if (x < minX) minX = x;
      if (x > maxX) maxX = x;

      if (y < minY) minY = y;
      if (y > maxY) maxY = y;

      if (z < minZ) minZ = z;
      if (z > maxZ) maxZ = z;

      vecVals.push_back(x);
      vecVals.push_back(y);
      vecVals.push_back(z);
    }
    else if (lineBuffer.find("vt") == 0)
    {
      std::istringstream ss(lineBuffer);
      std::string prefix;
      float x, y;

      ss >> prefix >> x >> y;
      if (ss.fail())
      {
        std::cerr << "Failed to parse line: " << lineBuffer << "!\n";
        ss.clear();
        continue;
      }

      texVals.push_back(x);
      texVals.push_back(y);
    }
    else if (lineBuffer.find("vn") == 0)
    {
      std::istringstream ss(lineBuffer);
      std::string prefix;
      float x, y, z;

      ss >> prefix >> x >> y >> z;
      if (ss.fail())
      {
        std::cerr << "Failed to parse line: " << lineBuffer << "!\n";
        ss.clear();
        continue;
      }

      normVals.push_back(x);
      normVals.push_back(y);
      normVals.push_back(z);
    }
    else if (lineBuffer.find("f") == 0)
    {
      std::istringstream ss(lineBuffer);
      std::string prefix;

      ss >> prefix;

      std::string triplet;
      while (ss >> triplet)
      {
        std::stringstream tripletStream(triplet);
        std::string value;

        while (std::getline(tripletStream, value, '/'))
        {
          if (value == "") continue;
          faceData.push_back(std::stoi(value));
        }
      }
      ss.clear();

      if (ss.fail())
      {
        std::cerr << "Failed to parse line: " << lineBuffer << "!\n";
        ss.clear();
        continue;
      }
    }
  }

  std::vector<GLfloat> vertices;
  std::vector<GLuint>  indices;

  bool hasDimensions =
    dimensions.x != 0 && dimensions.y != 0 && dimensions.z != 0;

  float length = hasDimensions ? maxX - minX : 1.f;
  float height = hasDimensions ? maxY - minY : 1.f;
  float width  = hasDimensions ? maxZ - minZ : 1.f;

  for (int i = 0; i < (int)(faceData.size() / 3); i++)
  {
    int posIndex = faceData.at(i * 3);
    int texIndex = faceData.at(i * 3 + 1);
    int normIndex = faceData.at(i * 3 + 2);

    vertices.push_back(vecVals.at((posIndex - 1) * 3)     / length);
    vertices.push_back(vecVals.at((posIndex - 1) * 3 + 1) / height);
    vertices.push_back(vecVals.at((posIndex - 1) * 3 + 2) / width);
    vertices.push_back(1.f);
    vertices.push_back(1.f);
    vertices.push_back(1.f);
    vertices.push_back(texVals.at((texIndex - 1) * 2));
    vertices.push_back(texVals.at((texIndex - 1) * 2 + 1));
    vertices.push_back(normVals.at((normIndex - 1) * 3));
    vertices.push_back(normVals.at((normIndex - 1) * 3 + 1));
    vertices.push_back(normVals.at((normIndex - 1) * 3 + 2));

    indices.push_back(i);
  }

  oVertices = vertices;
  oVerticesSize = sizeof(GLfloat) * vertices.size();
  oIndices = indices;
  oIndicesSize = sizeof(GLuint) * indices.size();

  return true;
}
