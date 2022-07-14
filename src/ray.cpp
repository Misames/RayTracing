#include "ray.hpp"

Ray::~Ray() {}

Ray::Ray() : origin(Point(0.f, 0.f, 0.f)), direction(0.f, 0.f, 0.f) {}

Ray::Ray(const Ray &r)
{
    this->origin = r.origin;
    this->direction = r.direction;
}

Ray::Ray(Point p, Vector v)
{
    this->origin = p;
    this->direction = v;
}

Ray::Ray(float x, float y, float z, float a, float b, float c)
{
    this->origin = Point(x, y, z);
    this->direction = Vector(a, b, c);
}
