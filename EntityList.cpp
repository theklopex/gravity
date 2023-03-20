#include "EntityList.h"
#include "Entity.h"

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