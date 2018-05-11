#include "OBSTACLE.h"
#ifndef LOWCOVER_H_INCLUDED
#define LOWCOVER_H_INCLUDED

class LowCover: public Obstacle{
    LowCover();

    //Checks if avatar is ducking
    isDucking();

    //blocks enemy vision if avatar is ducking
    blockVision();

};

#endif // LOWCOVER_H_INCLUDED
