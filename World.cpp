#include "World.h"
#include <math.h>
#include "Chunk.h"
#include <queue>
#ifdef DEBUG
#include <iostream>
#endif // DEBUG

World::World()
{

}

void World::randChunkGen(CoordsG location)
{
    while(world[location].entities.size() < 5)
    {
        int i = rand()%world[location].size;
        int j = rand()%world[location].size;

        static sf::CircleShape circle(70);
        circle.setFillColor(sf::Color::Blue);
        Entity temp;
        temp.loadGraphic(circle);
        temp.radius = 70;
        temp.position = CoordsP(i,j);
        temp.worldPos = CoordsW(i + location.x*Chunk::size, j + location.y*Chunk::size);

        #ifdef DEBUG
        std::cout << "Placing entity at " << temp.position.x << "," << temp.position.y << std::endl;
        #endif // DEBUG

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
        {
            world[location].addEntity(temp);
            #ifdef DEBUG
            std::cout << "Successful" << std::endl;
            #endif // DEBUG
        }

    }


}

void World::addEntity(Entity entity)
{
    CoordsG gridPos(entity.worldPos.x/Chunk::size, entity.worldPos.y/Chunk::size);
    world[gridPos].addEntity(entity);
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

    #ifdef DEBUG
    for(auto it=world.begin(); it != world.end(); it++)
        std::cout << it->first.x << "," << it->first.y << "\t";
    std::cout << std::endl;
    #endif // DEBUG

    int steps = ceil((float)radius / (float)Chunk::size);
    for(int i = currentChunkLocation.x - steps;
        i <= currentChunkLocation.x + steps; i++)
    {
        for (int j = currentChunkLocation.y - steps;
             j <= currentChunkLocation.y + steps; j++)
        {
            CoordsG displayLocation(i,j);
            #ifdef DEBUG
            std::cout << "Displaying chunk: " << i << "," << j << std::endl;
            #endif // DEBUG
            if(world.count(displayLocation) == 0)
            {
                #ifdef DEBUG
                std::cout << "Chunk not created...creating." << std::endl;
                #endif // DEBUG
                world[displayLocation] = Chunk(displayLocation);
                randChunkGen(displayLocation);
            }
            #ifdef DEBUG
            std::cout << "Printing " << world[displayLocation].entities.size() << " entities." << std::endl;
            #endif // DEBUG
            for( auto it = world[displayLocation].entities.begin(); it != world[displayLocation].entities.end(); it++ )
            {
                displayQueue.push(&(*it));
            }
        }
    }

    while(!displayQueue.empty())
    {
        window->draw(*(displayQueue.top()));
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

    int steps = ceil((float)radius / (float)Chunk::size);
    for(int i = currentChunkLocation.x - steps;
        i <= currentChunkLocation.x + steps; i++)
    {
        for (int j = currentChunkLocation.y - steps;
             j <= currentChunkLocation.y + steps; j++)
        {
            CoordsG updateLocation(i,j);
            if(!world.count(updateLocation))
            {
                world[updateLocation] = Chunk(updateLocation);
                randChunkGen(updateLocation);
            }
            for(auto it = world[updateLocation].entities.begin();
                it != world[updateLocation].entities.end(); it++ )
            {
                //it->update(this); // ***********************No system clock yet!***********************
            }
        }
    }
     while(!displayQueue.empty())
    {
        window->draw(*displayQueue.top());
        displayQueue.pop();
    }


}


