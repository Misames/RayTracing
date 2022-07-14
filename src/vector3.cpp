#include "vector3.h"
#include <cmath>

vecteur::vecteur() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

vecteur::vecteur(float a, float b, float c) {
	this->x = a;
	this->y = b;
	this->z = c;
}

vecteur& vecteur::operator*=(const float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

vecteur& vecteur::operator+=(const float a) {
	this->x += a;
	this->y += a;
	this->z += a;
	return *this;
}

vecteur& vecteur::operator-=(const float a) {
	this->x -= a;
	this->y -= a;
	this->z -= a;
	return *this;
}

vecteur& vecteur::operator/=(const float a) {
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

vecteur vecteur::normalized() {
	vecteur vecRet;
	vecRet.x = this->x / fabsf(this->x);
	vecRet.y = this->y / fabsf(this->y);
	vecRet.z = this->z / fabsf(this->z);
	return vecRet;
}

float vecteur::norm() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float vecteur::dot(vecteur vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

vecteur vecteur::oppose() {
	vecteur ret;
	ret.x = -this->x;
	ret.y = -this->y;
	ret.z = -this->z;
	return ret;
}

