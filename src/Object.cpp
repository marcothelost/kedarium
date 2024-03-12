#include "Kedarium/Object.hpp"

bool kdr::Object::loadFromObj(const std::string& objPath, GLfloat* oVertices, GLsizeiptr& oVerticesSize, GLuint* oIndices, GLsizeiptr& oIndicesSize)
{
  std::ifstream file(objPath);
  if (!file.is_open())
  {
    std::cerr << "Failed to open object file (\"" << objPath << "\")!" << '\n';
    return false;
  }

  std::vector<float> vecVals;
  std::vector<float> texVals;
  std::vector<int>   faceData;
  std::string        lineBuffer;

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

        int valueNumber = 0;
        while (std::getline(tripletStream, value, '/'))
        {
          if (valueNumber == 0)
          {
            faceData.push_back(std::stoi(value));
          }
          else if (valueNumber == 2)
          {
            faceData.push_back(std::stoi(value));
          }
          valueNumber++;
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

  for (int i = 0; i < faceData.size() / 2; i++)
  {
    int posIndex = faceData.at(i);
    int texIndex = faceData.at(i + 1);

    vertices.push_back(vecVals.at(posIndex));
    vertices.push_back(vecVals.at(posIndex + 1));
    vertices.push_back(vecVals.at(posIndex + 2));
    vertices.push_back(1.f);
    vertices.push_back(1.f);
    vertices.push_back(1.f);
    vertices.push_back(vecVals.at(texIndex));
    vertices.push_back(vecVals.at(texIndex + 1));

    indices.push_back(i);
  }

  oVertices = &vertices[0];
  oVerticesSize = sizeof(GLfloat) * vertices.size();
  oIndices = &indices[0];
  oIndicesSize = sizeof(GLuint) * indices.size();

  return true;
}
