#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D() : xv(0.0),
                       yv(0.0)
{
}

Vector2D::Vector2D(double x, double y) : xv(x),
                                         yv(y)
{
}

Vector2D::~Vector2D()
{
}

double Vector2D::getX() const
{
    return xv;
}

double Vector2D::getY() const
{
    return yv;
}

double Vector2D::mod() const
{
    return sqrt((xv * xv) + (yv * yv));
}

Vector2D Vector2D::operator+(const Vector2D &v) const
{
    return Vector2D(xv + v.xv, yv + v.yv);
}

Vector2D &Vector2D::operator*=(double f)
{
    xv = xv * f;
    yv = yv * f;
    return *this;
}
