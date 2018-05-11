#include "World.h"
#include <math.h>
#include "Chunk.h"
#include <queue>

void World::randChunkGen(CoordsG location)
{
    while(world[location].entities.size() < 12)
    {
        int i = rand()%world[location].size;
        int j = rand()%world[location].size;

        Entity temp;
        temp.position = CoordsP(i,j);

        bool intersect = false;

        for(auto it = world[location].entities.begin(); it != world[location].entities.end(); it++)
        {
            float radii = temp.radius + it->radius;
            float distance = sqrt(pow(temp.position.x - it->position.x, 2) + pow(temp.position.y - it->position.y, 2));
            if(distance <= radii)
            {
                intersect = true;
                break;
            }

        }
        if (intersect == false)
            world[location].addEntity(temp);

    }


}
void World::displayWorld(CoordsW location, int radius)
{
    /*
    convert location into coordsG
    for each chunk near the location
        find the distance between the chunk and the point
            if distance is less than radius

                for each entity in the chunk
                    add to the priority queue
    print each entity in the priority queue

    */
    std::priority_queue<Entity*> displayQueue;

    CoordsG currentChunkLocation;

    currentChunkLocation.x = location.x / Chunk::size;
    currentChunkLocation.y = location.y / Chunk::size;

    int steps = ceil(radius / Chunk::size);
    for(int i = currentChunkLocation.x - steps;
        i <= currentChunkLocation.x + steps; i++)
    {
        for (int j = currentChunkLocation.y - steps;
             j <= currentChunkLocation.y + steps; j++)
        {
            CoordsG displayLocation(i,j);
            if(!world.count(displayLocation))
            {
                world[displayLocation] = Chunk(location);
                randChunkGen(displayLocation);
            }
            for( auto it = world[displayLocation].entities.begin(); it != world[displayLocation].entities.end(); it++ )
            {
                displayQueue.push(&(*it));
            }
        }
    }

    while(!displayQueue.empty())
    {
        window->draw(*displayQueue.top());
        displayQueue.pop();
    }



}
void World::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}
void move(Entity& entity)
{

}
void World::randomWorld()
{
    Entity entity;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            CoordsG location(i,j);
            world[location] = Chunk(location);
            randChunkGen(location);
        }
    }

}


void World::updateWorld(CoordsW location, int radius)
{
        /*
    convert location into coordsG
    for each chunk near the location
        find the distance between the chunk and the point
            if distance is less than radius

                for each entity in the chunk
                    add update
    print each entity update

    */
    std::priority_queue<Entity*> displayQueue;

    CoordsG currentChunkLocation;

    currentChunkLocation.x = location.x / Chunk::size;
    currentChunkLocation.y = location.y / Chunk::size;

    int steps = ceil(radius / Chunk::size);
    for(int i = currentChunkLocation.x - steps;
        i <= currentChunkLocation.x + steps; i++)
    {
        for (int j = currentChunkLocation.y - steps;
             j <= currentChunkLocation.y + steps; j++)
        {
            for(auto it = world[displayLocation].entities.begin();
                it != world[displayLocation].entities.end(); it++ )
            {
                update();
            }
        }
    }
     while(!displayQueue.empty())
    {
        window->draw(*displayQueue.top());
        displayQueue.pop();
    }


}

