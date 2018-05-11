#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <vector>
#include <SFML/Graphics.hpp>

class Animation{

    //2d array of sprites
    std::vector<std::vector<sf::Sprite> > sprites;

    Animation(int mode, int frame);

};



#endif // ANIMATION_H_INCLUDED
