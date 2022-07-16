#include "Cube.h"

Point Cube::getTextureCoordinates(const Point& p) {
	Point lp = globalToLocal(p);
	if (lp[0] > 0.999 || lp[0] < -0.999)
		return Point(lp[2] / 2 + 0.5, lp[1] / 2 + 0.5, 0);
	if (lp[1] > 0.999 || lp[1] < -0.999)
		return Point(lp[0] / 2 + 0.5, lp[2] / 2 + 0.5, 0);
	if (lp[2] > 0.999 || lp[2] < -0.999)
		return Point(lp[0] / 2 + 0.5, lp[1] / 2 + 0.5, 0);
	return Point(0, 0, 0);
}

Ray Cube::getNormal(const Point& p, const Point& o) {
	Point lp = globalToLocal(p);
	Point lo = globalToLocal(o);
	Vec3 v(0, 0, 0);
	if (lp[0] > 0.999)v[0] = 1.0;
	else if (lp[0] < -0.999)v[0] = -1.0;
	else if (lp[1] > 0.999)v[1] = 1.0;
	else if (lp[1] < -0.999)v[1] = -1.0;
	else if (lp[2] > 0.999)v[2] = 1.0;
	else if (lp[2] < -0.999)v[2] = -1.0;
	if (lo[0]<1 && lo[0]>-1 && lo[1]<1 && lo[1]>-1 && lo[2]<1 && lo[2]>-1)
		return localToGlobal(Ray(lp, (v.oppose()).normalized()));
	return localToGlobal(Ray(lp, v.normalized()));
}

float Cube::interSide(const Ray& r, int dim, float offset)const {
	float t = -1;
	if (r.direction[dim]<0.00001 && r.direction[dim]>-0.00001)
		return -1;
	t = (offset - r.origin[dim]) / r.direction[dim];
	if (t < 0)
		return -1;
	for (int d = 0; d < 3; d++) {
		if (d == dim)
			continue;
		float x = r.origin[d] + t * r.direction[d];
		if (x < -1 || x > 1)
			return -1;
	}
	return t;
}

bool Cube::intersect(const Ray& ray, Point& impact) {
	Ray r = globalToLocal(ray);
	r.direction = r.direction.normalized();
	float mint = -1;
	float offsets[] = { -1,1 };
	for (int d = 0; d < 3; d++) {
		for (int o = 0; o < 2; o++) {
			float t = interSide(r, d, offsets[o]);
			if (t >= 0 && (mint<0 || mint>t)) {
				mint = t;
			}
		}
	}
	if (mint >= 0) {
		impact = localToGlobal((r.direction * mint) + r.origin );
		return true;
	}

	return false;
}