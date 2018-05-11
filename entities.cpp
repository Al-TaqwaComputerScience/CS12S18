#include "entities.h"
#include "Coords.h"

Entity::Entity(){

    position = CoordsP(0,0);
    sprite = NULL;
    passable = true;
    animation = NULL;
}

Entity::Entity(sf::Sprite sprite, CoordsP position){

    this->position = position;
    this->sprite = &sprite;

    passable = true;
    animation = NULL;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    target.draw(*sprite, states);
}

void Entity::loadSprite(sf::Sprite& sprite){
    this->sprite = &sprite;
}

void Entity::setPosition(CoordsP position){
    this->position = position;

}
