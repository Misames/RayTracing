#include "color.hpp"

Color::~Color() {}

Color::Color() : r(0), g(0), b(0) {}

Color::Color(const float R, const float G, const float B) : r(R), g(G), b(B) {}

Color::Color(const Color &col) : r(col.r), g(col.g), b(col.b) {}

Color Color::operator*(Color c) const
{
    Color ret;
    ret.r = this->r * c.r;
    ret.g = this->g * c.g;
    ret.b = this->b * c.b;
    return ret;
}