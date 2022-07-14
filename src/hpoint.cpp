#include "hpoint.hpp"

HPoint::~HPoint() {}

HPoint::HPoint() : Point(), w(1.f) {}

HPoint::HPoint(Point p, float w) : Point(p), w(w) {}

HPoint::HPoint(float a, float b, float c) : Point(a, b, c), w(1.f) {}

HPoint::HPoint(float x, float y, float z, float w) : Point(x, y, z), w(w) {}

float HPoint::Dot(HPoint hp)
{
    return this->x * hp.x + this->y * hp.y + this->z * hp.z;
}