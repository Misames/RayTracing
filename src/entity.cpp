#include "Entity.h"

Entity::Entity(matrix mat) {
	MatTransform.mat = mat.mat;
	MatTransformInv = mat.inverse();
}

void Entity::translate(float x, float y, float z) {

	matrix m;

	m.mat[0][3] += x;
	m.mat[1][3] += y;
	m.mat[2][3] += z;
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateX(float deg) {

	matrix m;

	m.mat[1][1] = cos(deg);
	m.mat[1][2] = -sin(deg);
	m.mat[2][1] = sin(deg);
	m.mat[2][2] = cos(deg);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateY(float deg) {

	matrix m;

	m.mat[0][0] = cos(deg);
	m.mat[0][2] = sin(deg);
	m.mat[2][0] = -sin(deg);
	m.mat[2][2] = cos(deg);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::rotateZ(float deg) {

	matrix m;

	m.mat[0][0] = cos(deg);
	m.mat[0][1] = -sin(deg);
	m.mat[1][0] = sin(deg);
	m.mat[1][1] = cos(deg);
	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

void Entity::scale(float factor) {
	matrix m;

	m.mat[0][0] = factor;
	m.mat[1][1] = factor;
	m.mat[2][2] = factor;

	this->MatTransform = m * this->MatTransform;
	this->MatTransformInv = this->MatTransform.inverse();
}

point Entity::localToGlobal(point p) {
	Hpoint hpo(p.x,p.y,p.z);
	Hpoint tmp = (this->MatTransformInv * hpo);
	point ret(tmp.x,tmp.y,tmp.z);
	return ret ;
}

vecteur Entity::localToGlobal(vecteur v) {
	Hvec3 hvect(v.x,v.y,v.z);
	Hvec3 tmp = (this->MatTransformInv * hvect);
	vecteur ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

ray Entity::localToGlobal( ray r) {
	//Convertion de l'origin
	Hpoint rorigin(r.origin.x, r.origin.y, r.origin.z);
	Hpoint retOr = this->MatTransformInv * rorigin;
	point pointOrigin(retOr.x, retOr.y, retOr.z);
	//convertion du vecteur directeur
	Hvec3 rdir(r.direction.x, r.direction.y, r.direction.z);
	Hvec3 retDir = this->MatTransformInv * rdir;
	vecteur vectDirecteur(retDir.x, retDir.y, retDir.z);

	return ray(pointOrigin,vectDirecteur);
}

point Entity::GlobalToLocal( point p) {
	Hpoint hpo(p.x, p.y, p.z);
	Hpoint tmp = (this->MatTransform * hpo);
	point ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

vecteur Entity::GlobalToLocal(vecteur v) {
	Hvec3 hvect(v.x, v.y, v.z);
	Hvec3 tmp = (this->MatTransform * hvect);
	vecteur ret(tmp.x, tmp.y, tmp.z);
	return ret;
}

ray Entity::GlobalToLocal( ray r) {
	//Convertion de l'origin
	Hpoint rorigin(r.origin.x, r.origin.y, r.origin.z);
	Hpoint retOr = this->MatTransform * rorigin;
	point pointOrigin(retOr.x, retOr.y, retOr.z);
	//convertion du vecteur directeur
	Hvec3 rdir(r.direction.x, r.direction.y, r.direction.z);
	Hvec3 retDir = this->MatTransform * rdir;
	vecteur vectDirecteur(retDir.x, retDir.y, retDir.z);

	return ray(pointOrigin, vectDirecteur);
}

