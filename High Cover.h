#include "OBSTACLE.h"
#ifndef HIGH_COVER_H_INCLUDED
#define HIGH_COVER_H_INCLUDED

Class HighCover: public Obstacle{
    HighCover();

    //Block enemy vision
    blockVision();
}


#endif // HIGH_COVER_H_INCLUDED

//Highcover can be renamed cover and made the parent class of low cover
//Blocking vision can be a characteristic/trait instead of a behaviour
