#include "Avatar.h"


void Avatar::moveAv()
{

}

bool Avatar::findPath(CoordsW target)
{
    return true;
}

void Avatar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void Avatar::update(World* world)
{
    if(delta == CoordsP(0,0))
        ;//this->animation->setAnimationMode(Avatar::IDLE);

}

bool Avatar::collision(Entity* entity)
{
    return false;
}
