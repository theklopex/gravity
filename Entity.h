#ifndef ENTITY_H
#define ENTITY_H

#include "Tuple.h"
#include <iostream>
#include <string>

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
  {}

  double distance(Entity& entity) const
  {
      return location.distance(entity.location);
  }

  void move(int64_t x, int64_t y, int64_t z)
  {
    location.move(x, y, z);
  }

  double get_mass()
  {
    return mass;
  }

  double get_radius()
  {
    return radius;
  }

  friend std::ostream& operator<<(std::ostream& stream, const Entity& entity);

private:
  std::string name;
  Tuple location;
  double mass;
  double radius;
};

#endif //ENTITY_H