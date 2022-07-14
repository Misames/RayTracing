#pragma once

#include "entity.hpp"
#include "color.hpp"

class Light : public Entity
{
public:
    Color id;
    Color is;

public:
    Ray getRayToLight(const Point &p) const;
    Ray getRayFromLight(const Point &p) const;
    Vector getVectorToLight(const Point &p) const;
    Vector getVectorFromLight(const Point &p) const;
};