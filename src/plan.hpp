#pragma once
#include "object.hpp"
#include "entity.hpp"
#include "ray.hpp"

class Plan : public Object
{
    Plan(Vector trans, float rot, float scal, std::vector<Material> mats) : Object(trans, rot, scal, mats) {}
    Point GetTextureCoordinates(const Point &p);
    Ray GetNormal(const Point &p, const Point &o);
    bool Intersect(const Ray &ray, Point &impact);
};
