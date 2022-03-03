#include "Vector3D.h"
#include <math.h>

// The Vector2D part is initialized by default
Vector3D::Vector3D() : zv(0.0)
{
}

Vector3D::Vector3D(double x, double y, double z) : Vector2D(x, y),
                                                   zv(z)
{
}

Vector3D::~Vector3D()
{
}

double Vector3D::getZ() const
{
  return zv;
}

// reimplement modulus calculation
double Vector3D::mod() const
{
  // xv and zv cannot be accessed directly, as they're private
  return sqrt((getX() * getX()) + (getY() * getY()) + (zv * zv));
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
  return Vector3D(xv + v.xv, yv + v.yv, zv + v.zv);
}
Vector3D Vector3D::operator-(const Vector3D &v) const
{
  return Vector3D(xv - v.xv, yv - v.yv, zv - v.zv);
}
Vector3D Vector3D::operator*(double f)
{
  xv = xv * f;
  yv = yv * f;
  zv = zv * f;
  return *this;
}

Vector3D &Vector3D::operator*=(double f)
{
  xv = xv * f;
  yv = yv * f;
  zv = zv * f;
  return *this;
}