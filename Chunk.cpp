#include "Chunk.h"

int Chunk::size = 100;

Chunk::Chunk()
{
    //ctor
}

Chunk::Chunk(CoordsG location)
{
    this->location = location;
}

void Chunk::addEntity(Entity entity)
{
    entities.push_back(entity);
}
