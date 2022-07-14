#include "point.hpp"

Point::~Point() {}

Point::Point() : x(0.f), y(0.f), z(0.f) {}

Point::Point(float a, float b, float c) : x(a), y(b), z(c) {}

Point::Point(const Point &p) : x(p.x), y(p.y), z(p.z) {}

Point Point::operator+(Point p)
{
    this->x += p.x;
    this->y += p.y;
    this->z += p.z;
    return *this;
}

Point Point::operator-(Point p)
{
    this->x -= p.x;
    this->y -= p.y;
    this->z -= p.z;
    return *this;
}

Point Point::operator*(float a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    return *this;
}

Point Point::operator/(float a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    return *this;
}

float Point::Dot(Point p)
{
    return this->x * p.x + this->y * p.y + this->z * p.z;
}

Point Point::Opposite()
{
    Point ret;
    ret.x = -this->x;
    ret.y = -this->y;
    ret.z = -this->z;
    return ret;
}
