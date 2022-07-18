#pragma once

#include <string>
#include "color.hpp"

using namespace std;

class Material
{
public:
    Color baseColor;
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
