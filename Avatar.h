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

    virtual bool collision(Entity* entity);

    enum animationModes {LEFT, RIGHT, IDLE, PICKUP, HIT};
};


#endif // AVATAR_H_INCLUDED
