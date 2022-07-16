#include "Hvector3.h"
#include <cmath>

Hvec3::Hvec3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Hvec3::Hvec3(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
	this->w = 0;
}


Hvec3& Hvec3::operator*=(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	this->w = 0;
	return *this;
}

Hvec3& Hvec3::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	this->w = 0;
	return *this;
}

Hvec3& Hvec3::operator-=(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	this->w = 0;
	return *this;
}

Hvec3& Hvec3::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	this->w = 0;
	return *this;
}

Hvec3 Hvec3::normalized() {
	Hvec3 vecRet;
	vecRet.x = this->x / fabsf(this->x);
	vecRet.y = this->y / fabsf(this->y);
	vecRet.z = this->z / fabsf(this->z);
	return vecRet;
}

float Hvec3::norm() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float Hvec3::dot(Hvec3 vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Hvec3 Hvec3::oppose() {
	Hvec3 ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}

