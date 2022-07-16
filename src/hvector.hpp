#pragma once

#include "vector.hpp"

class HVector : public Vector
{
public:
    float x;
    float y;
    float z;
    float w;

    ~HVector();
    HVector();
    HVector(float, float, float);

    HVector &operator*=(const float);
    HVector &operator+=(const float);
    HVector &operator-=(const float);
    HVector &operator/=(const float);

    HVector Opposite();
    HVector Normalized();
    float Dot(HVector);
    float Norm();
};
