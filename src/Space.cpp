#include "Kedarium/Space.hpp"

kdr::Space::Mat4 kdr::Space::rotate(const kdr::Space::Mat4& mat, float angle, const kdr::Space::Vec3& axes)
{
  kdr::Space::Vec3 normalizedAxes = kdr::Space::normalize(axes);
  kdr::Space::Mat4 result {mat};

  const float cosTheta = cosf(kdr::Space::radians(angle));
  const float sinTheta = sinf(kdr::Space::radians(angle));
  const float oneMinusCosTheta = 1 - cosTheta;

  result[0][0] = cosTheta + normalizedAxes.x * normalizedAxes.x * oneMinusCosTheta;
  result[0][1] = normalizedAxes.x * normalizedAxes.y * oneMinusCosTheta - normalizedAxes.z * sinTheta;
  result[0][2] = normalizedAxes.x * normalizedAxes.z * oneMinusCosTheta + normalizedAxes.y * sinTheta;
  result[1][0] = normalizedAxes.y * normalizedAxes.x * oneMinusCosTheta + normalizedAxes.z * sinTheta;
  result[1][1] = cosTheta + normalizedAxes.y * normalizedAxes.y * oneMinusCosTheta;
  result[1][2] = normalizedAxes.y * normalizedAxes.z * oneMinusCosTheta - normalizedAxes.x * sinTheta;
  result[2][0] = normalizedAxes.z * normalizedAxes.x * oneMinusCosTheta - normalizedAxes.y * sinTheta;
  result[2][1] = normalizedAxes.z * normalizedAxes.y * oneMinusCosTheta + normalizedAxes.x * sinTheta;
  result[2][2] = cosTheta + normalizedAxes.z * normalizedAxes.z * oneMinusCosTheta;

  return result * mat;
}

kdr::Space::Mat4 kdr::Space::ortho(const float left, const float right, const float bottom, const float top, const float zNear, const float zFar)
{
  kdr::Space::Mat4 result {1.f};
  
  result[0][0] =  2.f / (right - left);
  result[1][1] =  2.f / (top - bottom);
  result[2][2] = -2.f / (zFar - zNear);
  result[3][0] = -(right + left) / (right - left);
  result[3][1] = -(top + bottom) / (top - bottom);
  result[3][2] = -(zFar + zNear) / (zFar - zNear);

  return result;
}

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
