#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;

out vec3 vertCol;
out vec2 vertTex;

uniform mat4 cameraMatrix;

void main()
{
  vertCol = aCol;
  vertTex = aTex;
  gl_Position = cameraMatrix * vec4(aPos, 1.f);
}
