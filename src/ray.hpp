#pragma once

#include "point.hpp"
#include "vector.hpp"

class Ray
{
public:
    Point origin;
    Vector direction;

    ~Ray();
    Ray();
    Ray(const Ray &);
    Ray(Point, Vector);
    Ray(Point, Point);
    Ray(Vector, Vector);
    Ray(float, float, float, float, float, float);
};