#version 330 core

in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNorm;
in vec3 fragPos;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 lightCol;
uniform vec3 camPos;
uniform sampler2D tex0;

void main()
{
  float ambientFactor = 0.1f;
  vec3 ambient = lightCol * ambientFactor;

  vec3 normal = normalize(vertNorm);
  vec3 lightDirection = normalize(lightPos - fragPos);

  float diffFactor = max(dot(normal, lightDirection), 0.f);
  vec3 diffuse = diffFactor * lightCol;

  vec3 viewDirection = normalize(camPos - fragPos);
  vec3 reflectionDirection = reflect(-lightDirection, normal);

  float specularStrength = 0.5f;
  float specularFactor = pow(max(dot(viewDirection, reflectionDirection), 0.f), 32);
  vec3 specular = specularStrength * specularFactor * lightCol;

  vec3 lightFactor = ambient + diffuse + specular;
  FragColor = vec4(lightFactor, 1.f) * texture(tex0, vertTex);
}
