#include "Chunk.h"

int Chunk::size = 500;

Chunk::Chunk()
{
    location = CoordsG(0,0);
}

Chunk::Chunk(CoordsG location)
{
    this->location = location;
}

void Chunk::addEntity(Entity entity)
{
    entities.push_back(entity);
}
