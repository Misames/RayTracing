#pragma once

#include <cmath>
#include "object.hpp"

class Sphere : public Object
{
public:
    Sphere(Vector trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
    Point GetTextureCoordinates(const Point &p);
    Ray GetNormal(const Point &p, const Point &o);
    bool Intersec(const Ray &ray, Point &impact);
};
