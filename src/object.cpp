#include "object.hpp"
using namespace std;

Object::~Object() {}

Object::Object() : Entity() {}

Object::Object(Vector trans, float rot, float scal, vector<Material> mate) : Entity(trans, rot, scal), mats(mate) {}

Material Object::GetMaterial(const Point &p)
{
    Point lp = globalToLocal(p);
    //on check si l'objet a plusieurs matérials
    //Si oui si la coordonée en X est pair on prend le premier mat sinon on prend le deuxieme
    if(this->mats.size()>1){
        if (((int)lp.x *10)%2 == 0){
            return mats[0];
        }else{
            return mats[1];
        }
    }
    return mats[0];
}
