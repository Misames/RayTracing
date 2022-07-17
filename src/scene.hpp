#pragma once

#include <vector>
#include "light.hpp"
#include "color.hpp"
#include "object.hpp"

class Scene
{
private:
    Color backGroundColor;
    Color AmbianteColor;
    std::vector<Object *> listeObject;
    std::vector<Light *> listeLight;

public:
    // constructeur
    Scene(const Color, const Color, std::vector<Object *>, std::vector<Light *>);

    // Getter
    Color getBackground() const;
    Color getAmbiant() const;
    int nbLights() const;
    const Light *getLight(int index) const;

    // retourne un pointeur sur l'objet intersect� le plus proche par le rayon pass� en param�tre
    Object *closer_intersected(const Ray &ray, Point &impact) const;
};
