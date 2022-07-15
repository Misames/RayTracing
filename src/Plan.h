#pragma once
#include "Object.h"
#include "Entity.h"
#include "ray.h"

class Plan : public Object
{
	Plan(Vec3 trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
	Point getTextureCoordinates(const Point& p);
	Ray getNormal(const Point& p, const Point& o);
	bool intersect(const Ray& ray, Point& impact);
};

