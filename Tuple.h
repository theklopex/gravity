#ifndef TUPLE_H
#define TUPLE_H

#include <stdint.h>
#include <iostream>

class Tuple
{
public:
    Tuple()
    : x(0)
    , y(0)
    , z(0)
    {
    }

    Tuple(
        int64_t _x,
        int64_t _y,
        int64_t _z)
        : x(_x)
        , y(_y)
        , z(_z)
    {
    }

    double distance(const Tuple& tuple) const;

    void move(int64_t _x, int64_t _y, int64_t _z);

    inline bool operator==(const Tuple& other) const
    {
        return ((x == other.x) && (y == other.y) && (z == other.z));
    }

    Tuple operator+(const Tuple & obj)
    {
        Tuple res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        res.z = z + obj.z;
        return res;
    }

    Tuple operator-(const Tuple & obj)
    {
        Tuple res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        res.z = z - obj.z;
        return res;
    }

    void operator=(const Tuple & obj)
    {
        x = obj.x;
        y = obj.y;
        z = obj.z;
    }

    inline void relocate(int64_t _x, int64_t _y, int64_t _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    inline void relocate(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    void relocate(double _x, double _y, double _z);

    inline int64_t X()
    {
        return x;
    }

    inline int64_t Y()
    {
        return y;
    }

    inline int64_t Z()
    {
        return z;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Tuple& tuple);

private:
    int64_t x;
    int64_t y;
    int64_t z;
};


#endif //TUPLE_H