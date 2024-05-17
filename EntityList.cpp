#include "EntityList.h"
#include "Entity.h"

void EntityList::calculateForces(double secsToTranspire)
{
    // Zero all forces.
    for (Entity & anEntity : list)
    {
        anEntity.resetForce();
    }

    // Calculate all forces on all entities
    for (Entity & entity1 : list)
    {
        for (Entity & entity2 : list)
        {
            if (entity1.name == entity2.name)
            {
                // We don't need to calculate the gravity if both entities are the same thing.
                continue;
            }
            std::cout << "e1= " << entity1.name << std::endl;
            std::cout << "e2= " << entity2.name << std::endl;
            std::cout << std::endl;
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const EntityList& entityList)
{
    stream << "EntityList:" << std::endl;
    size_t size = entityList.list.size();
    for (size_t i = 0; i < size; i++)
    {
        stream << entityList.list[i] << std::endl;
    }
    return stream;
}