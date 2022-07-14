#pragma once

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

    Point operator+(Point);
    Point operator-(Point);
    Point operator*(float);
    Point operator/(float);

    float Dot(Point);
    Point Opposite();
};