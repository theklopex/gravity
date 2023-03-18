#include "Entity.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Entity& entity)
{
  stream << entity.name << ":"<< std::endl;
  stream << "  location: " << std::endl;
  stream << entity.location;
  stream << "  mass:     " << entity.mass << std::endl;
  stream << "  radius:   " << entity.radius << std::endl;
  return stream;
}