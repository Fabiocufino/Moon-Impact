#ifndef Vector2D_h
#define Vector2D_h

#include <iostream>

class Vector2D {

 public:

  Vector2D();
  Vector2D( double x, double y );
  ~Vector2D();

  double getX() const;
  double getY() const;

  double mod() const;


  Vector2D operator+( const Vector2D& v ) const;
  Vector2D& operator*=( double f );

  double xv;
  double yv;
 private:


};

#endif
