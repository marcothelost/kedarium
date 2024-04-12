#version 330 core

const int MAX_LIGHTS = 8;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNorm;

out vec3 vertCol;
out vec2 vertTex;
out vec3 vertNorm;
out vec3 fragPos;

uniform mat4 cameraMatrix;
uniform mat4 model;
uniform vec3 lightCol[MAX_LIGHTS];

void main()
{
  vertCol = aCol;
  vertTex = aTex;
  vertNorm = mat3(transpose(inverse(model))) * aNorm;
  fragPos = vec3(model * vec4(aPos, 1.f));
  gl_Position = cameraMatrix * model * vec4(aPos, 1.f);
}
