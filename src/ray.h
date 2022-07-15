#pragma once
#include "point.h"
#include "vector3.h"

class Ray 
{
public :

	Point origin;
	Vec3 direction;

public :
	Ray(float ox, float oy, float oz, float dx, float dy, float dz);
	Ray(Point p, Vec3 vec);
	Ray(Point p, Point p2);
};

