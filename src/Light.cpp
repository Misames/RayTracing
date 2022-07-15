#include "Light.h"

Ray Light::getRayToLight(const Point& p)const {
	Vec3 v(this->position.x, this->position.y, this->position.z);
	return Ray(p, v);
}

Ray Light::getRayFromLight(const Point& p)const {
	Vec3 v(p.x, p.y, p.z);
	return Ray( this->position,v);
}

Vec3 Light::getVectorToLight(const Point& p)const {
	Vec3 v(this->position.x - p.x, this->position.y - p.y, this->position.z - p.z);
	v.normalized();
	return v ;
}

Vec3 Light::getVectorFromLight(const Point& p)const {
	Vec3 v(p.x-this->position.x, p.y-this->position.y ,p.z - this->position.z);
	v.normalized();
	return v;
}