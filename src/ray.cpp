#include "ray.h"

ray::ray(float ox, float oy, float oz, float dx, float dy, float dz) {
	this->origin.x = ox;
	this->origin.y = oy;
	this->origin.z = oz;
	this->direction.x = dx;
	this->direction.y = dy;
	this->direction.z = dz;
}

ray::ray(point p, vecteur vec) {
	this->origin = p;
	this->direction = vec;
}