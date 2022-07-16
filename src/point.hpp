#pragma once

#include <cmath>

class Point
{
public:
    float x;
    float y;
    float z;

    ~Point();
    Point();
    Point(float, float, float);
    Point(const Point &);

    Point &operator*=(const float);
    Point &operator+=(const float);
    Point &operator-(const float);
    Point &operator/=(const float);
    float &operator[](const int);
    float operator[](const int) const;
    Point &operator-(const Point);

    float Dot(Point);
    Point Opposite();
    float Norm();
    Point Normalized();
};