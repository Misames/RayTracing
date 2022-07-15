#pragma once
#include "Entity.h"
#include "Color.h"

class Light : public Entity
{
public :
	Color id;
	Color is;

public :
	Ray getRayToLight(const Point& p)const;
	Ray getRayFromLight(const Point& p)const;
	Vec3 getVectorToLight(const Point& p)const;
	Vec3 getVectorFromLight(const Point& p)const;

};

