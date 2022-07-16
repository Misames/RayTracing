#pragma once
#include "object.hpp"
#include "entity.hpp"
#include "ray.hpp"

class Plan : public Object
{
    Plan(Vector trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
    Point GetTextureCoordinates(const Point &p);
    Ray GetNormal(const Point &p, const Point &o);
    bool Intersec(const Ray &ray, Point &impact);
};
