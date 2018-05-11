#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include <map>
#include <fstream>
#include "Coords.h"
#include "Chunk.h"

class World
{
private:

    std::map <CoordsG,Chunk> world;
    sf::RenderWindow* window;

public:

    void displayWorld(CoordsW location, int radius);
    void setWindow(sf::RenderWindow* window);
    void move(Entity& entity);
    void randomWorld();
    void randChunkGen(CoordsG location);
    void updateWorld(CoordsW location, int radius);

    World();

};

#endif // WORLD_H_INCLUDED
