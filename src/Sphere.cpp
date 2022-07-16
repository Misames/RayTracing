#include "Sphere.h"

Point Sphere::getTextureCoordinates(const Point& p) {
    Point lp = globalToLocal(p);
    float rho = std::sqrt(lp.dot(lp));
    float theta = std::atan2(lp[1], lp[0]);
    float sigma = std::acos(lp[2] / rho);
    float x = -theta / (2 * PI) + 0.5;
    float y = sigma / PI;
    	 		    	  	   	  
    return Point(x, y, 0);
}

Ray Sphere::getNormal(const Point& p, const Point& o) {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if ((lo - Point(0, 0, 0)).norm() < 1)
        return localToGlobal(Ray(lp, lp.oppose().normalized()));
    return localToGlobal(Ray(lp, lp.normalized()));
}

bool Sphere::intersect(const Ray& ray, Point& impact) {
	Ray r = globalToLocal(ray);
	r.direction.normalized();
	float a = r.direction.dot(r.direction);
	float b = 2 * r.direction.dot(r.origin);
	float c = r.origin.dot(r.origin) - 1.0;
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

	Point p = (r.direction*t)+ r.origin;
	impact = localToGlobal(p);
	return true;
}