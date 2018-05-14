#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED

#include "Coords.h"
#include "Entities.h"
#include "World.h"

class Avatar : public Entity
{
public:

    CoordsP delta;

    virtual void update(World* world);

    void moveAv();

    bool findPath(CoordsW target);

    virtual bool collision(Entity* entity);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    enum animationModes {LEFT, RIGHT, IDLE, PICKUP, HIT};
};


#endif // AVATAR_H_INCLUDED
