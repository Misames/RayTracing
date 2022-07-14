#pragma once
#include "point.h"
class Hpoint
{
public:
	float x;
	float y;
	float z;
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

