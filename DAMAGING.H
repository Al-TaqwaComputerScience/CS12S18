#ifndef DAMAGING_H_INCLUDED
#define DAMAGING_H_INCLUDED

#include "Entities.h"

class Damaging : public Entity
{
public:
    int damage;

    void Decrease_health();
};

#endif // DAMAGING_H_INCLUDED
