#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Tuple.h"
#include "ForceVector.h"

class Entity
{
public:
    // x, y, z are distances in meters from "the origin"
    // Mass is in grams
    Entity(std::string _name, int64_t _x, int64_t _y, int64_t _z, double _mass, double _radius)
    : name(_name)
    , location(_x, _y, _z)
    , mass(_mass)
    , radius(_radius)
    , forceVector()
    {}

    double distance(Entity& entity) const
    {
        return location.distance(entity.location);
    }

    void move(int64_t x, int64_t y, int64_t z)
    {
        location.move(x, y, z);
    }

    double get_mass() const
    {
        return mass;
    }

    double get_radius() const
    {
        return radius;
    }

    void print(std::ostream& stream) const;

    friend std::ostream& operator<<(std::ostream& stream, const Entity& entity);

    void resetForce()
    {
        forceVector.set(0, 0, 0);
    }

    void addForce(const ForceVector & _forceVector)
    {
        forceVector = forceVector + _forceVector;
    }

public:
    std::string name;
private:
    Tuple location;
    double mass;
    double radius;
    // For each step, all of the forces being applied to an entity will be calculated.  It will be stored here.
    ForceVector forceVector;
};

#endif //ENTITY_H