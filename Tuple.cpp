#include <tgmath.h>
#include <iostream>
#include "Tuple.h"

double Tuple::distance(const Tuple& tuple) const
{
  // Get the hypotenuse on the x-y plane.  But we don't need the square root of it.
  double x_y_hypotenuse_squared = pow(x-tuple.x, 2) + pow(y-tuple.y, 2);
  //std::cout << "    distance(): x_y_hypotenuse_squared = " << x_y_hypotenuse_squared << std::endl;
  // Get the hypotenuse of the z plane on the x-y hypotenuse plane.
  double distance = sqrt(pow(z-tuple.z, 2) + x_y_hypotenuse_squared);
  //std::cout << "    distance(): distance = " << distance << std::endl;
  return distance;
}

void Tuple::move(int64_t _x, int64_t _y, int64_t _z)
{
  x += _x;
  y += _y;
  z += _z;
}

void Tuple::relocate(double _x, double _y, double _z)
{
    // Round these values to the nearest decimal, otherwise 3.9999999 == 3.
    x = llrint(_x);
    y = llrint(_y);
    z = llrint(_z);
}

std::ostream& operator<<(std::ostream& stream, const Tuple& tuple)
{
    stream << "    x = " << tuple.x << std::endl;
    stream << "    y = " << tuple.y << std::endl;
    stream << "    z = " << tuple.z << std::endl;
    return stream;
}