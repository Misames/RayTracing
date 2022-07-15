#pragma once
#include "Object.h"
class Cube : public Object
{
	Cube(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	float interSide(const Ray& r, int dim, float offset)const;
	Point getTextureCoordinates(const Point& p);
	Ray getNormal(const Point& p, const Point& o);
	bool intersect(const Ray& ray, Point& impact);
};

