#version 330 core

const int MAX_LIGHTS = 8;

in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNorm;
in vec3 fragPos;

out vec4 FragColor;

uniform vec3  lightPos[MAX_LIGHTS];
uniform vec3  lightCol[MAX_LIGHTS];
uniform float lightInt[MAX_LIGHTS];

uniform int lightCount;
uniform vec3 camPos;
uniform sampler2D tex0;

void main()
{
  float ambientFactor = 0.15f;
  vec3 ambient = vec3(0.f);

  vec3 normal = normalize(vertNorm);
  vec3 viewDirection = normalize(camPos - fragPos);
  vec3 lightFactor = vec3(0.f);

  for (int i = 0; i < lightCount && i < MAX_LIGHTS; i++)
  {
    vec3 lightDirection = normalize(lightPos[i] - fragPos);    
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float distance = length(lightPos[i] - fragPos);

    float intensityAttenuation = 1.0 / (1.0 + 0.1 * distance + 0.01 * distance * distance) * lightInt[i];
    float attenuation = intensityAttenuation / (0.1f * distance * 0.3f * (distance * distance));

    float diffFactor = max(dot(normal, lightDirection), 0.f);
    vec3 diffuse = diffFactor * lightCol[i] * lightInt[i];

    float specularStrength = 0.5f;
    float specularFactor = pow(max(dot(viewDirection, reflectionDirection), 0.f), 32);
    vec3 specular = specularStrength * specularFactor * lightCol[i] * lightInt[i];

    ambient += lightCol[i] * ambientFactor * lightInt[i];
    lightFactor += (diffuse + specular) * attenuation;
  }

  vec3 finalColor = ambient + lightFactor;
  FragColor = vec4(finalColor, 1.f) * texture(tex0, vertTex);
}
