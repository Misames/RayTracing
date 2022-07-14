#pragma once
#include "matrix.h"
#include "ray.h"

class Entity
{

public :
	matrix MatTransform;
	matrix MatTransformInv;

public :
	Entity(matrix mat);
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

