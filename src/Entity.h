#pragma once
#include "matrix.h"
#include "ray.h"
#define PI 3.14159265


class Entity
{

protected :
	Matrix MatTransform;
	Matrix MatTransformInv;
	Vec3 position;

public :
	Entity(Matrix mat);
	Entity(Vec3 translation, float rotation, float scaling);
	void translate(float x, float y, float z);
	void rotateX(float deg);
	void rotateY(float deg);
	void rotateZ(float deg);
	void scale(float factor);
	Point localToGlobal( Point p);
	Vec3 localToGlobal(Vec3 p);
	Ray localToGlobal( Ray p);
	Point globalToLocal( Point p);
	Vec3 globalToLocal(Vec3 p);
	Ray globalToLocal( Ray p);

};

