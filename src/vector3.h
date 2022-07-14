#include "point.h"
class vecteur : public point
{
	
public:

	vecteur();
	vecteur(float a, float b, float c);

	vecteur& operator*= (const float a);
	vecteur& operator+= (const float a);
	vecteur& operator-= (const float a);
	vecteur& operator/= (const float a);

	vecteur normalized();
	float norm();
	float dot(vecteur vec);
	vecteur oppose();
	

};

