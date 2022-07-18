#pragma once
#include "object.hpp"

class Cylindre : public Object
{
public:
    Cylindre(Vector trans, float rot, float scal, std::vector<Material> mats) : Object(trans, rot, scal, mats) {}
    // retourne la normale correspondant au point de la surface de l'objet pass� en param�tre, observ� depuis le point pass� en second param�tre.
    Ray GetNormal(const Point &, const Point &);
    // calcul si il y a intersection, si oui renvoie true et met a jout le point d'impact pass� en param�tre sinon renvoie false
    bool Intersect(const Ray &, Point &);
};
