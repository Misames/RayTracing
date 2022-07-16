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
	//Constructeur
	Entity(Matrix mat);
	Entity(Vec3 translation, float rotation, float scaling);
	// applique une translation sur la matrice de position de l'entity
	void translate(float x, float y, float z);
	// applique une rotation sur la matrice de position de l'entity
	void rotateX(float deg);
	void rotateY(float deg);
	void rotateZ(float deg);
	// applique un scaling sur la matrice de position de l'entity
	void scale(float factor);
	//permet de changé de referentiel en passant de local a Global
	Point localToGlobal( Point p);
	Vec3 localToGlobal(Vec3 p);
	Ray localToGlobal( Ray p);
	//permet de changé de referentiel en passant de Global a Local
	Point globalToLocal( Point p);
	Vec3 globalToLocal(Vec3 p);
	Ray globalToLocal( Ray p);

};

