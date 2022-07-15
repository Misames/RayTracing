#include "vector3.h"
#include <cmath>

Vec3::Vec3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vec3::Vec3(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
}


Vec3& Vec3::operator*(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

Vec3& Vec3::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	return *this;
}

Vec3& Vec3::operator-=(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	return *this;
}

Vec3& Vec3::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

Vec3& Vec3::operator+(const Point p) {
	this->x =this->x + p.x;
	this->y = this->y + p.y;
	this->z = this->z + p.z;
	return *this;
}

float& Vec3::operator[](const int i) {
	if (i == 0)
		return this->x;

	if (i == 1)
		return this->y;

	if (i == 2)
		return this->z;
}

float Vec3::operator[](const int i)const{
	if (i == 0)
		return this->x;

	if (i == 1)
		return this->y;

	if (i == 2)
		return this->z;
}

Vec3 Vec3::normalized() {
	Vec3 vecRet;
	vecRet.x = this->x / fabsf(this->x);
	vecRet.y = this->y / fabsf(this->y);
	vecRet.z = this->z / fabsf(this->z);
	return vecRet;
}

float Vec3::norm() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float Vec3::dot(Vec3 vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}
float Vec3::dot(Point vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vec3 Vec3::oppose() {
	Vec3 ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}

