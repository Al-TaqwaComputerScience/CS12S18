#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED
#include "Coords.h"
#include "animation.h"
#include <SFML\GRAPHICS.HPP>

class World;

 class Entity: public sf::Drawable
 {
  public:

    CoordsP position;
    CoordsW worldPos;
    int radius;

    //Everything is drawable
    sf::Sprite* sprite;

    //a 2d array
    Animation* animation;

    //Determines if object is passable or not
    bool passable;

    Entity();

    Entity(sf::Sprite sprite, CoordsP position);

    void loadSprite(sf::Sprite& sprite);

    void setPosition(CoordsP position);




    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    virtual void update(sf::Clock clock, World *world);
    virtual bool collision(Entity *collider);

 };


#endif // ENTITIES_H_INCLUDED`
