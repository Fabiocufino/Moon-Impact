#ifndef Vector3D_h
#define Vector3D_h

#include "Vector2D.h"

// define a Vector3D as a Vector2D plus a z component
class Vector3D : public Vector2D
{

public:
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    double getZ() const;

    double mod() const;

    Vector3D operator+( const Vector3D& v ) const;
    Vector3D operator-( const Vector3D& v ) const;


    Vector3D operator*( double f );
    Vector3D& operator*=( double f );
    double zv;
private:
};

#endif
