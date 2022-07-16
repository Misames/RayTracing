#pragma once

#include "entity.hpp"
#include "color.hpp"

class Light : public Entity
{
public:
    Color id;
    Color is;

public:
    Ray GetRayToLight(const Point &) const;
    Ray GetRayFromLight(const Point &) const;
    Vector GetVectorToLight(const Point &) const;
    Vector GetVectorFromLight(const Point &) const;
};