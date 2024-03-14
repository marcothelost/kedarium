#version 330 core

const int MAX_LIGHTS = 8;

in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNorm;
in vec3 fragPos;

out vec4 FragColor;

uniform vec3 lightPos[MAX_LIGHTS];
uniform vec3 lightCol[MAX_LIGHTS];
uniform int lightCount;
uniform vec3 camPos;
uniform sampler2D tex0;

void main()
{
  float ambientFactor = 0.05f;
  vec3 ambient = vec3(0.f);

  vec3 normal = normalize(vertNorm);
  vec3 viewDirection = normalize(camPos - fragPos);
  vec3 lightFactor = vec3(0.f);

  for (int i = 0; i < lightCount && i < MAX_LIGHTS; i++)
  {
    vec3 lightDirection = normalize(lightPos[i] - fragPos);    
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float distance = length(lightPos[i] - fragPos);

    float attenuation = 1.f / (1.f * 0.1f * distance * 0.3f * (distance * distance));

    float diffFactor = max(dot(normal, lightDirection), 0.f);
    vec3 diffuse = diffFactor * lightCol[i];

    float specularStrength = 0.5f;
    float specularFactor = pow(max(dot(viewDirection, reflectionDirection), 0.f), 32);
    vec3 specular = specularStrength * specularFactor * lightCol[i];

    ambient += lightCol[i] * ambientFactor;
    lightFactor += (diffuse + specular) * attenuation;
  }

  vec3 finalColor = ambient + lightFactor;
  FragColor = vec4(finalColor, 1.f) * texture(tex0, vertTex);
}
