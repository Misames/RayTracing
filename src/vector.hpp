#pragma once

#include <cmath>
#include "point.hpp"

class Vector
{
public:
    float x;
    float y;
    float z;
    float w;

    ~Vector();
    Vector();
    Vector(const Vector &);
    Vector(float, float);
    Vector(float, float, float);
    Vector(float, float, float, float);

    Vector &operator*(const float);
    Vector &operator+=(const float);
    Vector &operator-=(const float);
    Vector &operator/=(const float);
    Vector &operator+(const Point);
    float &operator[](const int);
    float operator[](const int) const;

    operator Point() const
    {
        return Point(x, y, z);
    }

    Vector Opposite();
    Vector Normalized();
    float Norm();
    float Dot(Vector);
    float Dot(Point);
};
