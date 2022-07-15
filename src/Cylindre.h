#pragma once
#include "Object.h"
class Cylindre : public Object
{
public:
	Cylindre(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	//retourne la normale correspondant au point de la surface de l'objet passé en paramètre, observé depuis le point passé en second paramètre.
	Ray getNormal(const Point& p, const Point& o);
	// calcul si il y a intersection, si oui renvoie true et met a jout le point d'impact passé en paramètre sinon renvoie false
	bool intersect(const Ray& ray, Point& impact);
};

