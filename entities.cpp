#include "entities.h"
#include "Coords.h"

Entity::Entity(){

    position = CoordsP(0,0);
    radius = 0;
    sprite = NULL;
    passable = true;
    animation = NULL;
}

Entity::Entity(sf::Sprite sprite, CoordsP position){

    this->position = position;
    radius = 0;
    this->sprite = &sprite;

    passable = true;
    animation = NULL;
}

void Entity::loadSprite(sf::Sprite& sprite){
    this->sprite = &sprite;
}

void Entity::setPosition(CoordsP position){
    this->position = position;

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    if(sprite == NULL)
        return;
    sprite->setPosition(position.x, position.y);
    target.draw(*sprite, states);
}

void Entity::update(sf::Clock clock, World *world)
{

}

bool Entity::collision(Entity *collider)
{
    return false;
}
