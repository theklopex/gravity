#include <iostream>
#include "Entity.h"
#include "ForceVector.h"

std::ostream& operator<<(std::ostream& stream, const Entity& entity)
{
    stream << entity.name << ":"<< std::endl;
    stream << "  location: " << std::endl;
    stream << entity.location;
    stream << "  mass:         " << entity.mass << std::endl;
    stream << "  radius:       " << entity.radius << std::endl;
    stream << "  forceVector:  " << entity.forceVector << std::endl;
    return stream;
}


void Entity::print(std::ostream& stream) const
{
    stream << *this << std::endl;
}