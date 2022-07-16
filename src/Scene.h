#pragma once
#include "Light.h"
#include "Color.h"
#include "Object.h"
#include <vector>
class Scene
{
private :
	Color backGroundColor;
	Color AmbianteColor;
	std::vector<Object *> listeObject;
	std::vector<Light*> listeLight;

public :
	//constructeur
	Scene(const Color bgCol,const Color amCol, std::vector<Object*> listeObj,std::vector<Light*> listeL);
	//Getter
	Color getBackground() const;
	Color getAmbiant() const;
	int nbLights() const;
	const Light* getLight(int index) const;
	//retourne un pointeur sur l'objet intersecté le plus proche par le rayon passé en paramètre
	Object* closer_intersected(const Ray& ray, Point& impact)const;

};

