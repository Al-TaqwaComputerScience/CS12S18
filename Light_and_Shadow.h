#ifndef LIGHT_AND_SHADOW_H_INCLUDED
#define LIGHT_AND_SHADOW_H_INCLUDED

#include "Entities.h"

class Light_and_Shadow : public Entity
{
public:

	int heightOfObject;
	int widthOfObject;

	int widthOfShadow;
	int lengthOfShadow;

	//shadow boundary points
	int tr;
	int tl;
	int br;
	int bl;

	int directionOfLight;
	int directionOfShadow;

	void calculate_shadow();
	void draw();

};

#endif // LIGHT_AND_SHADOW_H_INCLUDED
