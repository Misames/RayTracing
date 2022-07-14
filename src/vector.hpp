#pragma once

#include <cmath>

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

    void operator=(const Vector &);
    Vector operator+(Vector);
    Vector operator-(Vector);
    Vector operator*(float);
    Vector operator/(float);

    Vector Opposite();
    Vector Normalized();
    float Norm();
    float Dot(Vector);
};
