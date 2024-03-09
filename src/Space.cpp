#include "Kedarium/Space.hpp"

kdr::Space::Mat4 kdr::Space::perspective(const float fov, const float aspect, const float zNear, const float zFar)
{
  kdr::Space::Mat4 result;
  const float halfTanFOV = tanf(kdr::Space::radians(fov)) / 2.f;

  result[0][0] = 1.f / (halfTanFOV * aspect);
  result[1][1] = 1.f / halfTanFOV;
  result[2][2] = (zFar + zNear) / (zNear - zFar);
  result[2][3] = -1.f;
  result[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

  return result;
}
