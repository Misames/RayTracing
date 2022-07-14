#include "hvector.hpp"

HVector::~HVector() {}

HVector::HVector() : Vector() {}

HVector::HVector(float a, float b, float c) : Vector(a, b, c, 0.f) {}

HVector &HVector::operator*=(const float a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    this->w = 0;
    return *this;
}

HVector &HVector::operator+=(const float a)
{
    this->x += a;
    this->y += a;
    this->z += a;
    this->w = 0;
    return *this;
}

HVector &HVector::operator-=(const float a)
{
    this->x -= a;
    this->y -= a;
    this->z -= a;
    this->w = 0;
    return *this;
}

HVector &HVector::operator/=(const float a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    this->w = 0;
    return *this;
}

HVector HVector::Normalized()
{
    HVector vecRet;
    vecRet.x = this->x / fabsf(this->x);
    vecRet.y = this->y / fabsf(this->y);
    vecRet.z = this->z / fabsf(this->z);
    return vecRet;
}

float HVector::Norm()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float HVector::Dot(HVector vec)
{
    return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

HVector HVector::Opposite()
{
    HVector ret;
    ret.x = -this->x;
    ret.y = -this->y;
    ret.z = -this->z;
    return ret;
}