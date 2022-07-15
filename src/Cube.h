#pragma once
#include "Object.h"
class Cube : public Object
{
	Cube(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	float interSide(const Ray& r, int dim, float offset)const;
	//renvoie le Point 2D de la texture correspondant au point d'impact pass� en param�tre
	Point getTextureCoordinates(const Point& p);
	//retourne la normale correspondant au point de la surface de l'objet pass� en param�tre, observ� depuis le point pass� en second param�tre.
	Ray getNormal(const Point& p, const Point& o);
	// calcul si il y a intersection, si oui renvoie true et met a jout le point d'impact pass� en param�tre sinon renvoie false
	bool intersect(const Ray& ray, Point& impact);
};

