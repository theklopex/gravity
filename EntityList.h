
#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <vector>
#include <iostream>
#include "Entity.h"

class EntityList
{
public:
    EntityList()
    : list()
    {
        iter = list.begin();
    }

    // Resets the EntityList's iterator
    void reset()
    {
        iter = list.begin();
    }

    void addEntity(std::string _name, int64_t _x, int64_t _y, int64_t _z, double _mass, double _radius)
    {
        // This will call the constructor for Entity and create it inside of the space in the vector.
        list.emplace_back(_name, _x, _y, _z, _mass, _radius);
    }

    void addEntity(Entity & entity)
    {
        list.push_back(entity);
    }

    void calculateForces(double secsToTranspire);

    friend std::ostream& operator<<(std::ostream& stream, const EntityList& entityList);

private:
    std::vector<Entity> list;
    std::vector<Entity>::iterator iter;

};

#endif //ENTITY_LIST_H