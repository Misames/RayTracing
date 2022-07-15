#pragma once
#include "Object.h"
#include <cmath>
class Sphere : public Object
{
	Sphere(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	Point getTextureCoordinates(const Point& p);
	Ray getNormal(const Point& p, const Point& o);
	bool intersect(const Ray& ray, Point& impact);
};

