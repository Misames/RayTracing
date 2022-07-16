#pragma once
#include"Color.h"


class Material
{
public :
	Color Kambiante;
	Color Kdiffuse;
	Color kspeculaire;
	float shininess;

public :
	Material();
	Material(Color am, Color dif, Color spec,float shini);
	//Seter
	void SetKambiante(Color col);
	void SetKdiffuse(Color col);
	void SetKspeculaire(Color col);
	void SetShininess(float f);

};

