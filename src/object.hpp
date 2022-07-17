#pragma once
#include "entity.hpp"
#include "material.hpp"
#include <vector>

class Object : public Entity
{
public:
    std::vector<Material> mats;

    ~Object();
    Object();
    Object(Vector trans, float rot, float scal, std::vector<Material> mate): Entity(trans, rot, scal){
        this->mats = mate;
    };

    Material GetMaterial(const Point &p);

    //Fonction surchargé dans les différents Objets, initialisé par default pour un plan
    virtual Point getTextureCoordinates(const Point& p);
	virtual Ray getNormal(const Point& p, const Point& o);
	virtual bool intersect(const Ray& ray, Point& impact);
};
