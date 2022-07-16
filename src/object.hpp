#pragma once
#include "entity.hpp"
#include "material.hpp"

class Object : public Entity
{
public:
    Material mat;

    ~Object();
    Object();
    Object(Vector, float, float, Material);

    Material GetMaterial(const Point &);
};
