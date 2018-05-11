#ifndef CHUNK_H
#define CHUNK_H
#include "Coords.h"
#include <vector>
#include "Entities.h"

class World;

class Chunk
{
private:
    CoordsG location;
    static int size;
    std::vector<Entity> entities;

public:
    Chunk();
    Chunk(CoordsG location);
    void addEntity(Entity entity);

    //static int getSize();
    //static void setSize(int size);

    friend World;
};

#endif // CHUNK_H
