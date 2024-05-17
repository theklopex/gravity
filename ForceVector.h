#ifndef FORCE_VECTOR_H
#define FORCE_VECTOR_H

#include "Tuple.h"

class ForceVector : public Tuple
{
public:
    // Creates a forceVector that is in the direction of an object at <direction>, with magnitude 
    ForceVector()
    : Tuple(0,0,0)
    {}

    ForceVector(Tuple& direction, double magnitude);

    friend std::ostream& operator<<(std::ostream& stream, const ForceVector& forceVector);

    void set(int64_t x, int64_t y, int64_t z)
    {
        relocate(x, y, z);
    }

    void operator= (const Tuple & obj)
    {
        *(dynamic_cast<Tuple*>(this)) = obj;
    }

private:
};

#endif //FORCE_VECTOR_H