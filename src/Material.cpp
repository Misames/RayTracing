#include "Material.h"

Material::Material() {
	this->Kambiante = Color(0, 0, 0);
	this->Kdiffuse = Color(0, 0, 0);
	this->kspeculaire = Color(0, 0, 0);
	this->shininess = 0;
}

Material::Material(Color am, Color dif, Color spec, float shini) {
	this->Kambiante = am;
	this->Kdiffuse = dif;
	this->kspeculaire = spec;
	this->shininess = shini;
}

void Material::SetKambiante(Color col) {
	this->Kambiante = col;
}

void Material::SetKdiffuse(Color col) {
	this->Kdiffuse = col;
}

void Material::SetKspeculaire(Color col) {
	this->kspeculaire = col;
}

void Material::SetShininess(float f) {
	this->shininess = f;
}