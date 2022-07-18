#pragma once

#include "entity.hpp"
#include "color.hpp"

class Light : public Entity
{
public:
    Color id;
    Color is;

public:
    Light(Vector position, float rotation, float scale);
// renvoie le rayon qui part du point passé en parametre jusqu'a la lumiere
    Ray GetRayToLight(const Point &) const;
    // renvoie le rayon qui part de la lumiere jusqu'au point passé en parametre
    Ray GetRayFromLight(const Point &) const;
    // renvoie le vecteur qui part du point passé en parametre jusqu'a la lumiere
    Vector GetVectorToLight(const Point &) const;
    // renvoie le vecteur qui part de la lumiere jusqu'au point passé en parametre
    Vector GetVectorFromLight(const Point &) const;
};