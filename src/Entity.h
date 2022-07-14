#pragma once
#include "matrix.h"
#include "ray.h"
#define PI 3.14159265


class Entity
{

protected :
	matrix MatTransform;
	matrix MatTransformInv;
	point position;

public :
	Entity(matrix mat);
	Entity(vecteur translation, float rotation, float scaling);
	void translate(float x, float y, float z);
	void rotateX(float deg);
	void rotateY(float deg);
	void rotateZ(float deg);
	void scale(float factor);
	point localToGlobal( point p);
	vecteur localToGlobal(vecteur p);
	ray localToGlobal( ray p);
	point GlobalToLocal( point p);
	vecteur GlobalToLocal(vecteur p);
	ray GlobalToLocal( ray p);

};

