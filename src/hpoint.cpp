#include "HPoint.hpp"

HPoint::~HPoint() {}

HPoint::HPoint() : Point(), w(1.f) {}

HPoint::HPoint(Point p, float w) : Point(p), w(w) {}

HPoint::HPoint(float a, float b, float c) : Point(a, b, c), w(1.f) {}

HPoint::HPoint(float x, float y, float z, float w) : Point(x, y, z), w(w) {}

HPoint &HPoint::operator*=(const float a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    this->w = 1;
    return *this;
}

HPoint &HPoint::operator+=(const float a)
{
    this->x += a;
    this->y += a;
    this->z += a;
    this->w = 1;
    return *this;
}

HPoint &HPoint::operator-=(const float a)
{
    this->x -= a;
    this->y -= a;
    this->z -= a;
    this->w = 1;
    return *this;
}

HPoint &HPoint::operator/=(const float a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    this->w = 1;
    return *this;
}

float HPoint::Dot(HPoint point)
{
    return this->x * point.x + this->y * point.y + this->z * point.z;
}

HPoint HPoint::Opposite()
{
    HPoint ret;
    ret.x = -this->x;
    ret.y = -this->y;
    ret.z = -this->z;
    return ret;
}
