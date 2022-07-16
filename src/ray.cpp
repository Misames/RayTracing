#include "ray.h"

Ray::Ray(float ox, float oy, float oz, float dx, float dy, float dz) {
	this->origin.x = ox;
	this->origin.y = oy;
	this->origin.z = oz;
	this->direction.x = dx;
	this->direction.y = dy;
	this->direction.z = dz;
}

Ray::Ray(Point p, Vec3 vec) {
	this->origin = p;
	this->direction = vec;
}
Ray::Ray(Point p, Point p2) {
	this->origin = p;
	this->direction.x = p2.x;
	this->direction.y = p2.y;
	this->direction.z = p2.z;
}