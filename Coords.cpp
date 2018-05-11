#include "Coords.h"

Coords::Coords()
{
    x = 0;
    y = 0;
}
Coords::Coords(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coords Coords::operator= (Coords rhs){
        this->x = rhs.x;
        this->y = rhs.y;
}

bool operator == (Coords &lhs, const Coords rhs){
    return(lhs.y == rhs.y && lhs.x == rhs.x);
}

bool operator!=(Coords &lhs, Coords &rhs){
    return !(lhs==rhs);
}

bool operator < (Coords &lhs, const Coords rhs){
    if(lhs.y < rhs.y)
        return true;

    if (lhs.y == rhs.y){
        return lhs.x < rhs.x;
    }
}

bool operator <= (Coords &lhs, Coords rhs){
    return (lhs < rhs || lhs == rhs);
}

bool operator > (Coords &lhs, const Coords rhs){
    return !(lhs <= rhs);
}

bool operator >= (Coords &lhs, const Coords rhs){
    return !(lhs < rhs);
}


CoordsP::CoordsP()
{
    x = 0;
    y = 0;
}
CoordsP::CoordsP(int x,  int y)
{
    this->x = x;
    this->y = y;
}
CoordsW::CoordsW()
{
    x = 0;
    y = 0;
}
CoordsW::CoordsW(int x, int y)
{
    this->x = x;
    this->y = y;
}
CoordsG::CoordsG()
{
    x = 0;
    y = 0;
}
CoordsG::CoordsG(int x, int y)
{
    this->x = x;
    this->y = y;
}






