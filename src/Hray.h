#pragma once
#include "Hpoint.h"
#include "Hvector3.h"

//Rayon 3D en coordon�es Homog�ne (avec une dimension en plus, utilis� pour le changement de rep�re)
class Hray
{
public:

	Hpoint origin;
	Hvec3 direction;

public:
	Hray(float ox, float oy, float oz, float dx, float dy, float dz);
	Hray(Hpoint p, Hvec3 vec);
};

