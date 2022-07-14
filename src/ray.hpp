#pragma once

#include "point.hpp"
#include "vector.hpp"

class Ray
{
public:
    Point origin;
    Vector direction;
    Ray();
    Ray(const Ray &);
    Ray(Point, Vector);
    Ray(float, float, float, float, float, float);
    ~Ray();
};