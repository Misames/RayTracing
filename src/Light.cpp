#include "Light.h"

ray Light::getRayToLight(const point& p)const {
	vecteur v(this->position.x, this->position.y, this->position.z);
	return ray(p, v);
}

ray Light::getRayFromLight(const point& p)const {
	vecteur v(p.x, p.y, p.z);
	return ray( this->position,v);
}

vecteur Light::getVectorToLight(const point& p)const {
	vecteur v(this->position.x - p.x, this->position.y - p.y, this->position.z - p.z);
	v.normalized();
	return v ;
}

vecteur Light::getVectorFromLight(const point& p)const {
	vecteur v(p.x-this->position.x, p.y-this->position.y ,p.z - this->position.z);
	v.normalized();
	return v;
}