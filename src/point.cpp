#include "point.h"

point::point() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

point::point(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
}

point& point::operator*=(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

point& point::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	return *this;
}

point& point::operator-=(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	return *this;
}

point& point::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

float point::dot(point vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

point point::oppose() {
	point ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}

