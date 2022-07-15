#pragma once
#include "Object.h"
#include "Entity.h"
#include "ray.h"

class Plan : public Object
{
	Plan(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	//renvoie le Point 2D de la texture correspondant au point d'impact passé en paramètre
	Point getTextureCoordinates(const Point& p);
	//retourne la normale correspondant au point de la surface de l'objet passé en paramètre, observé depuis le point passé en second paramètre.
	Ray getNormal(const Point& p, const Point& o);
	// calcul si il y a intersection, si oui renvoie true et met a jout le point d'impact passé en paramètre sinon renvoie false
	bool intersect(const Ray& ray, Point& impact);
};

