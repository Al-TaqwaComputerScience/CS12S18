#include "animation.h"

Animation::Animation(int mode, int frame)
{
    sprites.resize(mode);

    for(int i = 0; i < sprites.size(); i++){
        sprites[i].resize(frame);
    }
}

