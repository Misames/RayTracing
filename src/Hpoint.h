#pragma once
#include "point.h"
//Point 3D en coordonées Homogène (avec une dimension en plus, utilisé pour le changement de repère)
class Hpoint : public Point
{
public:
	float w = 1;

public:
	Hpoint();
	Hpoint(float a, float b, float c);
	
	Hpoint& operator*= (const float a);
	Hpoint& operator+= (const float a);
	Hpoint& operator-= (const float a);
	Hpoint& operator/= (const float a);
	float dot(Hpoint vec);
	Hpoint oppose();
	
};

