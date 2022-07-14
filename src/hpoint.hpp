#pragma once

#include "point.hpp"

class HPoint : public Point
{
public:
    float w;

    ~HPoint();
    HPoint();
    HPoint(Point, float);
    HPoint(float, float, float);
    HPoint(float, float, float, float);

    float Dot(HPoint);
};
