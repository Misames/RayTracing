#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "light.hpp"
#include "color.hpp"
#include "object.hpp"
#include "material.hpp"

using json = nlohmann::json;
using namespace std;

class Scene
{

public:
    Color backGroundColor;
    Color AmbianteColor;

    vector<Object> listeObject;
    vector<Light> listeLight;

    // constructeur
    Scene();
    Scene(const Color, const Color, std::vector<Object>, std::vector<Light>);
    Scene(const string scenePath);

    // Getter
    Color getBackground() const;
    Color getAmbiant() const;
    int nbLights() const;
    const Light getLight(int index) const;

    // retourne un pointeur sur l'objet intersect� le plus proche par le rayon pass� en param�tre
    Object *closerIntersected(const Ray &ray, Point &impact) const;
};
