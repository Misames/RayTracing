#include "Scene.h"

Scene::Scene(const Color bgCol, const Color amCol, std::vector<Object*> listeObj, std::vector<Light*> listeL) {
	this->AmbianteColor = amCol;
	this->backGroundColor = bgCol;
	this->listeObject = listeObj;
	this->listeLight = listeL;
}

Color Scene::getBackground() const {
	return this->backGroundColor;
}

Color Scene::getAmbiant() const {
	return this->AmbianteColor;
}

int Scene::nbLights() const {
	return listeLight.size();
}

const Light* Scene::getLight(int index) const {
	return listeLight[index];
}

Object* Scene::closer_intersected(const Ray& ray, Point& impact)const {

}