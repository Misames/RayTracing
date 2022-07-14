#pragma once
#include "Hpoint.h"

class point
{
public :
	float x;
	float y;
	float z;

public :
	point();
	point(float a, float b, float c);
	point& operator*= (const float a);
	point& operator+= (const float a);
	point& operator-= (const float a);
	point& operator/= (const float a);
	float dot(point vec);
	point oppose();
	

};

