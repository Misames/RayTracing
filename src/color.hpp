#pragma once

class Color
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