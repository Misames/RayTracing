#pragma once

#include "object.hpp"
#include "vector.hpp"

class Cube : public Object
{
    Cube(Vector trans, float rot, float scal, Material mat) : Object(trans, rot, scal, mat) {}
    float interSide(const Ray &, int, float) const;
    // renvoie le Point 2D de la texture correspondant au point d'impact pass� en param�tre
    Point GetTextureCoordinates(const Point &);
    // retourne la normale correspondant au point de la surface de l'objet pass� en param�tre, observ� depuis le point pass� en second param�tre.
    Ray GetNormal(const Point &, const Point &);
    // calcul si il y a intersection, si oui renvoie true et met a jout le point d'impact pass� en param�tre sinon renvoie false
    bool Intersec(const Ray &, Point &);
};
