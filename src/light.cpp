#include "light.hpp"

Light::Light(Vector position, float rotation, float scale):Entity(position,rotation,scale){}

Ray Light::GetRayToLight(const Point &p) const
{
    Vector v(this->position.x, this->position.y, this->position.z);
    return Ray(p, v);
}

Ray Light::GetRayFromLight(const Point &p) const
{
    Vector v = Vector(p.x, p.y, p.z);
    return Ray(this->position, v);
}

Vector Light::GetVectorToLight(const Point &p) const
{
    Vector v(this->position.x - p.x, this->position.y - p.y, this->position.z - p.z);
    v.Normalized();
    return v;
}

Vector Light::GetVectorFromLight(const Point &p) const
{
    Vector v(p.x - this->position.x, p.y - this->position.y, p.z - this->position.z);
    v.Normalized();
    return v;
}