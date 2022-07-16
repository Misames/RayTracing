#include "Entity.h"

Entity::Entity(Matrix mat) {
	MatTransform.mat = mat.mat;
	MatTransformInv = mat.inverse();
	position = Vec3(mat.mat[0][3], mat.mat[1][3], mat.mat[2][3]);
	
}

Entity::Entity(Vec3 translation , float rotation , float scaling) {
	
	translate(translation.x, translation.y, translation.z);
	rotateX(rotation);
	rotateY(rotation);
	rotateZ(rotation);
	scale(scaling);

}

void Entity::translate(float x, float y, float z) {

	Matrix m;

	m.mat[0][3] += x;
	m.mat[1][3] += y;
	m.mat[2][3] += z;
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateX(float deg) {

	Matrix m;
	float rad = deg * PI / 180;
	m.mat[1][1] = cos(rad);
	m.mat[1][2] = -sin(rad);
	m.mat[2][1] = sin(rad);
	m.mat[2][2] = cos(rad);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateY(float deg) {

	Matrix m; 
	float rad = deg * PI / 180;
	m.mat[0][0] = cos(rad);
	m.mat[0][2] = sin(rad);
	m.mat[2][0] = -sin(rad);
	m.mat[2][2] = cos(rad);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateZ(float deg) {

	Matrix m;
	float rad = deg * PI / 180;

	m.mat[0][0] = cos(rad);
	m.mat[0][1] = -sin(rad);
	m.mat[1][0] = sin(rad);
	m.mat[1][1] = cos(rad);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::scale(float factor) {
	Matrix m;

	m.mat[0][0] = factor;
	m.mat[1][1] = factor;
	m.mat[2][2] = factor;

	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

Point Entity::localToGlobal(Point p) {
	Hpoint hpo(p.x,p.y,p.z);
	Hpoint tmp = (this->MatTransformInv * hpo);
	Point ret(tmp.x,tmp.y,tmp.z);
	return ret ;
}

Vec3 Entity::localToGlobal(Vec3 v) {
	Hvec3 hvect(v.x,v.y,v.z);
	Hvec3 tmp = (this->MatTransformInv * hvect);
	Vec3 ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

Ray Entity::localToGlobal( Ray r) {
	//Convertion de l'origin
	Hpoint rorigin(r.origin.x, r.origin.y, r.origin.z);
	Hpoint retOr = this->MatTransformInv * rorigin;
	Point pointOrigin(retOr.x, retOr.y, retOr.z);
	//convertion du vecteur directeur
	Hvec3 rdir(r.direction.x, r.direction.y, r.direction.z);
	Hvec3 retDir = this->MatTransformInv * rdir;
	Vec3 vectDirecteur(retDir.x, retDir.y, retDir.z);

	return Ray(pointOrigin,vectDirecteur);
}

Point Entity::globalToLocal( Point p) {
	Hpoint hpo(p.x, p.y, p.z);
	Hpoint tmp = (this->MatTransform * hpo);
	Point ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

Vec3 Entity::globalToLocal(Vec3 v) {
	Hvec3 hvect(v.x, v.y, v.z);
	Hvec3 tmp = (this->MatTransform * hvect);
	Vec3 ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

Ray Entity::globalToLocal( Ray r) {
	//Convertion de l'origin
	Hpoint rorigin(r.origin.x, r.origin.y, r.origin.z);
	Hpoint retOr = this->MatTransform * rorigin;
	Point pointOrigin(retOr.x, retOr.y, retOr.z);
	//convertion du vecteur directeur
	Hvec3 rdir(r.direction.x, r.direction.y, r.direction.z);
	Hvec3 retDir = this->MatTransform * rdir;
	Vec3 vectDirecteur(retDir.x, retDir.y, retDir.z);

	return Ray(pointOrigin, vectDirecteur);
}

