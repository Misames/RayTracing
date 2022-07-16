#pragma once

#include "color.hpp"

class Material
{
public:
    Color Kambiante;
    Color Kdiffuse;
    Color kspeculaire;
    float shininess;

    Material();
    Material(Color, Color, Color, float);

    void SetKambiante(Color);
    void SetKdiffuse(Color);
    void SetKspeculaire(Color);
    void SetShininess(float);
};
