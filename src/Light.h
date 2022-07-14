#pragma once
#include "Entity.h"
#include "Color.h"

class Light : public Entity
{
public :
	Color id;
	Color is;

public :
	ray getRayToLight(const point& p)const;
	ray getRayFromLight(const point& p)const;
	vecteur getVectorToLight(const point& p)const;
	vecteur getVectorFromLight(const point& p)const;

};

