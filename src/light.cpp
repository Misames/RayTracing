#include "light.hpp"

Ray Light::getRayToLight(const Point &p) const
{
    Vector v(this->position.x, this->position.y, this->position.z);
    return Ray(p, v);
}

Ray Light::getRayFromLight(const Point &p) const
{
    Vector v(p.x, p.y, p.z);
    return Ray(this->position, v);
}

Vector Light::getVectorToLight(const Point &p) const
{
    Vector v(this->position.x - p.x, this->position.y - p.y, this->position.z - p.z);
    v.Normalized();
    return v;
}

Vector Light::getVectorFromLight(const Point &p) const
{
    Vector v(p.x - this->position.x, p.y - this->position.y, p.z - this->position.z);
    v.Normalized();
    return v;
}