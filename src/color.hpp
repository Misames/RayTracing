#pragma once

class Color
{
public:
    float r;
    float g;
    float b;

    ~Color();
    Color();
    Color(const float R, const float G, const float B);
    Color(const Color &col);

    Color operator*(Color c) const;
};