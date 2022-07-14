#pragma once
#include "point.h"
#include "vector3.h"

class ray
{
public :

	point origin;
	vecteur direction;

public :
	ray(float ox, float oy, float oz, float dx, float dy, float dz);
	ray(point p, vecteur vec);
};

