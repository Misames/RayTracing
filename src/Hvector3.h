#pragma once
#include "Hpoint.h"
//Vecteur 3D en coordonées Homogène (avec une dimension en plus, utilisé pour le changement de repère)
class Hvec3 : public Hpoint
{
public:
	float w = 0;

public:

	Hvec3();
	Hvec3(float a, float b, float c);
	

	Hvec3& operator*= (const float a);
	Hvec3& operator+= (const float a);
	Hvec3& operator-= (const float a);
	Hvec3& operator/= (const float a);

	Hvec3 normalized();
	float norm();
	float dot(Hvec3 vec);
	Hvec3 oppose();
	

};
