#pragma once
#include "object.hpp"
class Color : public Object
{
public:
    float r;
    float g;
    float b;

    ~Color();
    Color();
    Color(const float, const float, const float);
    Color(const Color &);

    Color operator*(Color c) const;
};