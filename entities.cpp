#include "entities.h"
#include "Coords.h"

Entity::Entity(){

    position = CoordsP(0,0);
    radius = 0;
    sprite = NULL;
    passable = true;
    animation = NULL;
    this->sprite = new sf::CircleShape(10);
    this->sprite->setFillColor(sf::Color::Blue);
}

Entity::Entity(sf::Sprite sprite, CoordsP position){

    this->position = position;
    radius = 10;
    //this->sprite = &sprite;
    this->sprite = new sf::CircleShape(10);
    this->sprite->setFillColor(sf::Color::Blue);

    passable = true;
    animation = NULL;
}

void Entity::loadSprite(sf::Sprite& sprite){
    //this->sprite = &sprite;
}

void Entity::setPosition(CoordsP position){
    this->position = position;

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    if(sprite == NULL)
        return;
    sprite->setPosition(worldPos.x, worldPos.y);
    target.draw(*sprite, states);
}

void Entity::update(sf::Clock clock, World *world)
{

}

bool Entity::collision(Entity *collider)
{
    return false;
}
