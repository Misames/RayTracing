#pragma once
#include "Object.h"
class Cylindre : public Object
{
public:
	Cylindre(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	Ray getNormal(const Point& p, const Point& o);
	bool intersect(const Ray& ray, Point& impact);
};

