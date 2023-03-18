#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

class Vector : public Tuple
{
public:
    // Creates a vector that is in the direction of an object at <direction>, with magnitude 
    Vector()
    : Tuple(0,0,0)
    {}

    Vector(Tuple& direction, double magnitude);

    friend std::ostream& operator<<(std::ostream& stream, const Vector& vector);

private:
};

#endif //VECTOR_H