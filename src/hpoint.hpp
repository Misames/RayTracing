#pragma once

#include "point.hpp"

class HPoint : public Point
{
public:
    float w = 1;

    ~HPoint();
    HPoint();
    HPoint(Point, float);
    HPoint(float, float, float);
    HPoint(float, float, float, float);

    HPoint &operator*=(const float);
    HPoint &operator+=(const float);
    HPoint &operator-=(const float);
    HPoint &operator/=(const float);
    HPoint Opposite();

    float Dot(HPoint);
};
