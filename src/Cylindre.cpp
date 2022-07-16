#include "Cylindre.h"


Ray Cylindre::getNormal(const Point& p, const Point& o) {
	Point lp = globalToLocal(p);
	Point lo = globalToLocal(o);
	if ((lo - Point(0, lo[1], 0)).norm() > 1)
		return localToGlobal(Ray(lp, Vec3(lp[0], 0, lp[2]).normalized()));
	return localToGlobal(Ray(lp, Vec3(-lp[0], 0, -lp[2]).normalized()));
}

bool Cylindre::intersect(const Ray& ray, Point& impact) {
	Ray r = globalToLocal(ray);
	r.direction.normalized();
	float a = r.direction[0] * r.direction[0] + r.direction[2] * r.direction[2];
	float b = 2 * (r.direction[0] * r.origin[0] + r.direction[2] * r.origin[2]);
	float c = r.origin[0] * r.origin[0] + r.origin[2] * r.origin[2] - 1.0;
	float delta = b * b - 4 * a * c;

	if (delta < 0)
		return false;

	float t;
	if (delta < 0.0001) {
		t = -b / (2 * a);
	}
	else {
		t = (-b - sqrt(delta)) / (2 * a);
		if (t < 0)t = (-b + sqrt(delta)) / (2 * a);
	}
	if (t < 0)
		return false;

	Point p = (r.direction*t) + r.origin ;
	impact = localToGlobal(p);
	return true;
}