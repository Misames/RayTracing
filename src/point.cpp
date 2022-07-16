#include "point.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Point::Point(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
}

Point::Point(const Point& p) {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Point& Point::operator*=(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

Point& Point::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	return *this;
}

Point& Point::operator-(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	return *this;
}

Point& Point::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

float& Point::operator[](const int i) {
	if (i == 0)
		return this->x;

	if (i == 1)
		return this->y;

	if (i == 2)
		return this->z;
}

float Point::operator[](const int i) const{
	if (i == 0)
		return this->x;

	if (i == 1)
		return this->y;

	if (i == 2)
		return this->z;
}

Point& Point::operator-(const Point p) {
	this->x = this->x + p.x;
	this->y = this->y + p.y;
	this->z = this->z + p.z;
	return *this;
}

float Point::dot(Point vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Point Point::oppose() {
	Point ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}

float Point::norm() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}


Point Point::normalized() {
	Point vecRet;
	vecRet.x = this->x / fabsf(this->x);
	vecRet.y = this->y / fabsf(this->y);
	vecRet.z = this->z / fabsf(this->z);
	return vecRet;
}
