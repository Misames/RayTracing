#include "scene.hpp"
using namespace std;

Scene::Scene(const Color bgCol, const Color amCol, vector<Object *> listeObj, vector<Light *> listeL)
{
    this->AmbianteColor = amCol;
    this->backGroundColor = bgCol;
    this->listeObject = listeObj;
    this->listeLight = listeL;
}

Color Scene::getBackground() const
{
    return this->backGroundColor;
}

Color Scene::getAmbiant() const
{
    return this->AmbianteColor;
}

int Scene::nbLights() const
{
    return listeLight.size();
}

const Light *Scene::getLight(int index) const
{
    return listeLight[index];
}

Object *Scene::closer_intersected(const Ray &ray, Point &impact) const
{
    return nullptr;
}