#pragma once

class Point
{
private:
    float x;
    float y;
    float z;

public:
    Point();
    ~Point();
    Point(float, float, float);
    Point(const Point &);
    Point operator+(Point);
    Point operator-(Point);
    Point operator*(float);
    Point operator/(float);
    float Dot();
};