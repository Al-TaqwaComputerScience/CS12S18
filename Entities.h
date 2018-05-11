#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED
#include <SFML\GRAPHICS.HPP>

 class Entity
 {
  public:

    CoordsP position;

    //Everything is drawable
    sf::Sprite* sprite;

    //a 2d array
//    Animation* animation;

    //Determines if object is passable or not
    bool passable;

    Entity();

    Entity(sf::Sprite sprite, CoordsP position);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      target.draw(*sprite,states);
    }

    void loadSprite(sf::Sprite sprite);

    void setPosition(CoordsP position);



 };


#endif // ENTITIES_H_INCLUDED
