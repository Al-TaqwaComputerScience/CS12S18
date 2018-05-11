#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED
#include <SFML\GRAPHICS.HPP>

class Coords{
public:

    int x;
    int y;

    Coords();
    Coords(int x, int y);

    Coords operator= (Coords rhs);
};

bool operator == (Coords &lhs, const Coords rhs);
bool operator!=(Coords &lhs, Coords &rhs);
bool operator > (Coords &lhs, const Coords rhs);
bool operator < (Coords &coord, const Coords rhs);
bool operator <= (Coords &lhs, Coords rhs);
bool operator >= (Coords &lhs, Coords rhs);

//Position based on pixels
class CoordsP: public Coords{
public:
    CoordsP();
    CoordsP(int x, int y);
};

//Position based on in game measurement
class CoordsW: public Coords{
public:
    CoordsW();
    CoordsW(int x, int y);

};

//Position based chunks
class CoordsG: public Coords{
public:
    CoordsG();
    CoordsG(int x, int y);

};

#endif
