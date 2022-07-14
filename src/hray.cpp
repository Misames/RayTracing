#include "Hray.h"

Hray::Hray(float ox, float oy, float oz, float dx, float dy, float dz) {
	this->origin.x = ox;
	this->origin.y = oy;
	this->origin.z = oz;
	this->origin.w = 1;
	this->direction.x = dx;
	this->direction.y = dy;
	this->direction.z = dz;
	this->direction.w = 1;
}

Hray::Hray(Hpoint p, Hvec3 vec) {
	this->origin = p;
	this->direction = vec;
}