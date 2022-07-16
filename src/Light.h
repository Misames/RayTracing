#pragma once
#include "Entity.h"
#include "Color.h"

class Light : public Entity
{
public :
	Color id;
	Color is;

public :
	// renvoie le rayon qui part du point passé en parametre jusqu'a la lumiere
	Ray getRayToLight(const Point& p)const;
	// renvoie le rayon qui part de la lumiere jusqu'au point passé en parametre
	Ray getRayFromLight(const Point& p)const;
	// renvoie le vecteur qui part du point passé en parametre jusqu'a la lumiere
	Vec3 getVectorToLight(const Point& p)const;
	// renvoie le vecteur qui part de la lumiere jusqu'au point passé en parametre
	Vec3 getVectorFromLight(const Point& p)const;

};

