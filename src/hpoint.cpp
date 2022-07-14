#include "Hpoint.h"

Hpoint::Hpoint() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
}

Hpoint::Hpoint(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
	this->w = 1;
}

Hpoint& Hpoint::operator*=(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	this->w = 1;
	return *this;
}

Hpoint& Hpoint::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	this->w = 1;
	return* this;
}

Hpoint& Hpoint::operator-=(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	this->w = 1;
	return *this;
}

Hpoint& Hpoint::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	this->w = 1;
	return *this;
}

float Hpoint::dot(Hpoint point) {
	return this->x * point.x + this->y * point.y + this->z * point.z;
}

Hpoint Hpoint::oppose() {
	Hpoint ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}
