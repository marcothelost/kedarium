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

kdr::Space::Mat4 kdr::Space::lookAt(const kdr::Space::Vec3& eye, const kdr::Space::Vec3& target, const kdr::Space::Vec3& up)
{
  kdr::Space::Vec3 front = kdr::Space::normalize(eye - target);
  kdr::Space::Vec3 right = kdr::Space::normalize(kdr::Space::cross(up, front));
  kdr::Space::Vec3 newUp = kdr::Space::cross(front, right);
  kdr::Space::Mat4 result;

  result[0][0] = right.x;
  result[1][0] = right.y;
  result[2][0] = right.z;
  result[0][1] = newUp.x;
  result[1][1] = newUp.y;
  result[2][1] = newUp.z;
  result[0][2] = front.x;
  result[1][2] = front.y;
  result[2][2] = front.z;
  result[3][0] = -kdr::Space::dot(right, eye);
  result[3][1] = -kdr::Space::dot(newUp, eye);
  result[3][2] = -kdr::Space::dot(front, eye);
  result[3][3] = 1.f;

  return result;
}
