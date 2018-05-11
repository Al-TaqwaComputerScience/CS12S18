#include "Avatar.h"

void Avatar::update()
{

}

void Avatar::moveAv()
{

}

void Avatar::draw()
{

}

virtual void update(World* world)
    {
        if(delta == CoordsP(0,0))
            this->animation->setAnimationMode(Avatar::IDLE);

    }
