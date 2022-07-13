#pragma once

#include "point.hpp"
#include "vector.hpp"

class Ray
{
private:
public:
    Point origin;
    Vector vector;
    Ray();
    Ray(const Ray &);
    Ray(Point, Vector);
    Ray(float, float, float, float, float, float);
    ~Ray();
};