#version 330 core

in vec3 vertCol;
in vec2 vertTex;

out vec4 FragColor;

uniform sampler2D tex0;

void main()
{
  FragColor = texture(tex0, vertTex);
}
