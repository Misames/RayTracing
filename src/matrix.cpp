#include "matrix.h"

matrix::matrix() {
	this->mat = { 0 };
}

matrix::matrix(float x0y0, float x0y1, float x0y2, float x0y3, float x1y0, float x1y1, float x1y2, float x1y3, float x2y0, float x2y1, float x2y2, float x2y3, float x3y0, float x3y1, float x3y2, float x3y3) {
	this->mat[0][0] = x0y0;
	this->mat[0][1] = x0y1;
	this->mat[0][2] = x0y2;
	this->mat[0][3] = x0y3;

	this->mat[1][0] = x1y0;
	this->mat[1][1] = x1y1;
	this->mat[1][2] = x1y2;
	this->mat[1][3] = x1y3;
						 
	this->mat[2][0] = x2y0;
	this->mat[2][1] = x2y1;
	this->mat[2][2] = x2y2;
	this->mat[2][3] = x2y3;
						 
	this->mat[3][0] = x3y0;
	this->mat[3][1] = x3y1;
	this->mat[3][2] = x3y2;
	this->mat[3][3] = x3y3;
}

matrix matrix::inverse() {

	float A2323 = this->mat[2][2] * this->mat[3][3] - this->mat[2][3] * this->mat[3][2];
	float A1323 = this->mat[2][1] * this->mat[3][3] - this->mat[2][3] * this->mat[3][1];
	float A1223 = this->mat[2][1] * this->mat[3][2] - this->mat[2][2] * this->mat[3][1];
	float A0323 = this->mat[2][0] * this->mat[3][3] - this->mat[2][3] * this->mat[3][0];
	float A0223 = this->mat[2][0] * this->mat[3][2] - this->mat[2][2] * this->mat[3][0];
	float A0123 = this->mat[2][0] * this->mat[3][1] - this->mat[2][1] * this->mat[3][0];
	float A2313 = this->mat[1][2] * this->mat[3][3] - this->mat[1][3] * this->mat[3][2];
	float A1313 = this->mat[1][1] * this->mat[3][3] - this->mat[1][3] * this->mat[3][1];
	float A1213 = this->mat[1][1] * this->mat[3][2] - this->mat[1][2] * this->mat[3][1];
	float A2312 = this->mat[1][2] * this->mat[2][3] - this->mat[1][3] * this->mat[2][2];
	float A1312 = this->mat[1][1] * this->mat[2][3] - this->mat[1][3] * this->mat[2][1];
	float A1212 = this->mat[1][1] * this->mat[2][2] - this->mat[1][2] * this->mat[2][1];
	float A0313 = this->mat[1][0] * this->mat[3][3] - this->mat[1][3] * this->mat[3][0];
	float A0213 = this->mat[1][0] * this->mat[3][2] - this->mat[1][2] * this->mat[3][0];
	float A0312 = this->mat[1][0] * this->mat[2][3] - this->mat[1][3] * this->mat[2][0];
	float A0212 = this->mat[1][0] * this->mat[2][2] - this->mat[1][2] * this->mat[2][0];
	float A0113 = this->mat[1][0] * this->mat[3][1] - this->mat[1][1] * this->mat[3][0];
	float A0112 = this->mat[1][0] * this->mat[2][1] - this->mat[1][1] * this->mat[2][0];

	//Calcul du determinant
	float det = this->mat[0][0] * (this->mat[1][1] * A2323 - this->mat[1][2] * A1323 + this->mat[1][3] * A1223)
		- this->mat[0][1] * (this->mat[1][0] * A2323 - this->mat[1][2] * A0323 + this->mat[1][3] * A0223)
		+ this->mat[0][2] * (this->mat[1][0] * A1323 - this->mat[1][1] * A0323 + this->mat[1][3] * A0123)
		- this->mat[0][3] * (this->mat[1][0] * A1223 - this->mat[1][1] * A0223 + this->mat[1][2] * A0123);
	det = 1 / det;

	matrix ret;

	ret.mat[0][0] = det * (this->mat[1][1] * A2323 - this->mat[1][2] * A1323 + this->mat[1][3] * A1223);
	ret.mat[0][1] = det * -(this->mat[0][1] * A2323 - this->mat[0][2] * A1323 + this->mat[0][3] * A1223);
	ret.mat[0][2] = det * (this->mat[0][1] * A2313 - this->mat[0][2] * A1313 + this->mat[0][3] * A1213);
	ret.mat[0][3] = det * -(this->mat[0][1] * A2312 - this->mat[0][2] * A1312 + this->mat[0][3] * A1212);
	ret.mat[1][0] = det * -(this->mat[1][0] * A2323 - this->mat[1][2] * A0323 + this->mat[1][3] * A0223);
	ret.mat[1][1] = det * (this->mat[0][0] * A2323 - this->mat[0][2] * A0323 + this->mat[0][3] * A0223);
	ret.mat[1][2] = det * -(this->mat[0][0] * A2313 - this->mat[0][2] * A0313 + this->mat[0][3] * A0213);
	ret.mat[1][3] = det * (this->mat[0][0] * A2312 - this->mat[0][2] * A0312 + this->mat[0][3] * A0212);
	ret.mat[2][0] = det * (this->mat[1][0] * A1323 - this->mat[1][1] * A0323 + this->mat[1][3] * A0123);
	ret.mat[2][1] = det * -(this->mat[0][0] * A1323 - this->mat[0][1] * A0323 + this->mat[0][3] * A0123);
	ret.mat[2][2] = det * (this->mat[0][0] * A1313 - this->mat[0][1] * A0313 + this->mat[0][3] * A0113);
	ret.mat[2][3] = det * -(this->mat[0][0] * A1312 - this->mat[0][1] * A0312 + this->mat[0][3] * A0112);
	ret.mat[3][0] = det * -(this->mat[1][0] * A1223 - this->mat[1][1] * A0223 + this->mat[1][2] * A0123);
	ret.mat[3][1] = det * (this->mat[0][0] * A1223 - this->mat[0][1] * A0223 + this->mat[0][2] * A0123);
	ret.mat[3][2] = det * -(this->mat[0][0] * A1213 - this->mat[0][1] * A0213 + this->mat[0][2] * A0113);
	ret.mat[3][3] = det * (this->mat[0][0] * A1212 - this->mat[0][1] * A0212 + this->mat[0][2] * A0112);

	return ret;

}

void matrix::operator=(const matrix& m) {
	this->mat = m.mat;
}

matrix matrix::operator*(const matrix& m) {
	matrix ret;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ret.mat[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				ret.mat[i][j] += this->mat[i][k] * (m.mat[k][j]);
			}
		}
	}
	return ret;
}

Hpoint matrix::operator*(const Hpoint& p) {
	Hpoint ret;
	ret.x = (this->mat[0][0] * p.x) + (this->mat[0][1] * p.y) + (this->mat[0][2] * p.z) + (this->mat[0][3] * p.w);
	ret.y = (this->mat[1][0] * p.x) + (this->mat[1][1] * p.y) + (this->mat[1][2] * p.z) + (this->mat[1][3] * p.w);
	ret.z = (this->mat[2][0] * p.x) + (this->mat[2][1] * p.y) + (this->mat[2][2] * p.z) + (this->mat[2][3] * p.w);
	ret.w = (this->mat[3][0] * p.x) + (this->mat[3][1] * p.y) + (this->mat[3][2] * p.z) + (this->mat[3][3] * p.w);
	return ret;
}

Hvec3 matrix::operator*(const Hvec3& v) {
	Hvec3 vec;
	vec.x = (this->mat[0][0] * v.x) + (this->mat[0][1] * v.y) + (this->mat[0][2] * v.z) + (this->mat[0][3] * v.w);
	vec.y = (this->mat[1][0] * v.x) + (this->mat[1][1] * v.y) + (this->mat[1][2] * v.z) + (this->mat[1][3] * v.w);
	vec.z = (this->mat[2][0] * v.x) + (this->mat[2][1] * v.y) + (this->mat[2][2] * v.z) + (this->mat[2][3] * v.w);
	vec.w = (this->mat[3][0] * v.x) + (this->mat[3][1] * v.y) + (this->mat[3][2] * v.z) + (this->mat[3][3] * v.w);
	return vec;
}
