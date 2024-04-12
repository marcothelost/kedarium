#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;

out vec2 vertTex;

uniform mat4 cameraMatrix;
uniform vec2 position;

void main()
{
  vertTex = aTex;
  gl_Position = cameraMatrix * vec4((aPos + position), 1.f, 1.f);
}
