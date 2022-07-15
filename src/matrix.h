#pragma once
#include <array>
#include "Hpoint.h"
#include "Hvector3.h"

class Matrix
{
public :

	std::array<std::array<float, 4>, 4> mat;

public :
	//matrice par defaut = matrice identité
	Matrix();
	Matrix(float x0y0, float x0y1, float x0y2, float x0y3, float x1y0, float x1y1, float x1y2, float x1y3, float x2y0, float x2y1, float x2y2, float x2y3, float x3y0, float x3y1, float x3y2, float x3y3);
	//matrice inverse
	Matrix inverse();
	void operator=(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Hpoint operator*(const Hpoint& p);
	Hvec3 operator*(const Hvec3& v);

};

