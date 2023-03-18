#include <cmath>
#include <iostream>
#include "Vector.h"

Vector::Vector(Tuple& direction, double magnitude)
: Tuple()
{
    double x;
    double y;
    double z;

    /*
    y
    ^
    |  /
    | /
    |/  theta
    ---------------> x
    tan theta = y/x

    z
    ^
    | phi/
    |  /
    |/
    -----------------> xy_distance
    */

    //std::cout << "Vector constructor, input tuple: " << std::endl << direction;

    // Theta is the number of degrees the line is off of the positive X axis on the X-Y plane
    double theta;
    if (direction.X() == 0)
    {
        // 90 degrees
        theta = M_PI/2;
    }
    else
    {
        theta = atan(static_cast<double>(direction.Y()) / static_cast<double>(direction.X()));
    }
    //std::cout << "    theta = " << theta << "  " << (180 / M_PI) * theta << std::endl;

    // The distance the projection of the point on the X-Y plane is from the origin.
    double xy_distance = sqrt(pow(direction.X(), 2) + pow(direction.Y(), 2));
    //std::cout << "    xy_distance = " << xy_distance << std::endl;
    
    // Phi is the number of degrees the line is off the positive Z axis toward the point.
    double phi;
    if (direction.Z() == 0)
    {
        phi =  M_PI/2;
    }
    else
    {
        phi = atan(xy_distance / static_cast<double>(direction.Z()));
    }
    //std::cout << "    phi = " << phi << "  " << (180 / M_PI) * phi << std::endl;

    // Use the magnitude to determine X, Y, and Z.
    z = cos(phi) * magnitude;
    //std::cout << "    z = " << z << std::endl;
    xy_distance = sin(phi) * magnitude;
    //std::cout << "    xy_distance = " << xy_distance << std::endl;

    x = cos(theta) * xy_distance;
    y = sin(theta) * xy_distance;
    //std::cout << "    x = " << x << std::endl;
    //std::cout << "    y = " << y << std::endl;

    //std::cout << "theta = " << theta << "  " << (180 / M_PI) * theta << std::endl;
    //std::cout << "phi = " << phi << "  " << (180 / M_PI) * phi << std::endl;
    //std::cout << "xy_distance = " << xy_distance << std::endl;
    //std::cout << "x = " << x << std::endl;
    //std::cout << "y = " << y << std::endl;
    //std::cout << "z = " << z << std::endl;
    //std::cout << "magnitude = " << magnitude << std::endl;

    relocate(x,y,z);
}

std::ostream& operator<<(std::ostream& stream, const Vector& vector)
{
    stream << "Vector:" << std::endl;
    stream << *(dynamic_cast<const Tuple*>(&vector));
    double magnitude = vector.distance(Tuple(0,0,0));
    stream << "    magnitude = " << magnitude << std::endl;
    return stream;
}