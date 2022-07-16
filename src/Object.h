#pragma once
#include "Entity.h"
#include "Material.h"

class Object : public Entity
{
public :
	Material mat;

public :
	Object(Vec3 trans, float rot, float scal, Material mate) : Entity(trans, rot, scal) {
		this->mat = mate;
	};
	Material getMaterial(const Point& p);
	// On d�clare uniquement ces fonctions sans les d�finir car elle seront surcharg� dans les classes des diff�rents objects
	virtual Point getTextureCoordinates(const Point& p);
	virtual Ray getNormal(const Point& p, const Point& o);
	virtual bool intersect(const Ray& ray, Point& impact);
};

