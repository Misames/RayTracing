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
	// On déclare uniquement ces fonctions sans les définir car elle seront surchargé dans les classes des différents objects
	virtual Point getTextureCoordinates(const Point& p);
	virtual Ray getNormal(const Point& p, const Point& o);
	virtual bool intersect(const Ray& ray, Point& impact);
};

