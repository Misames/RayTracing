#include "point.h"
class Vec3 : public Point
{
	
public:

	Vec3();
	Vec3(float a, float b, float c);

	Vec3& operator* (const float a);
	Vec3& operator+= (const float a);
	Vec3& operator-= (const float a);
	Vec3& operator/= (const float a);
	Vec3& operator+(const Point v);
	float& operator[](const int i);
	float operator[](const int i)const;
	//normalisation du vecteur 
	Vec3 normalized();
	//renvoie la norme du vecteur
	float norm();
	//renvoie le resultat d'un scalaire avec un vecteur ou un point
	float dot(Vec3 vec);
	float dot(Point vec);
	//renvoie le vecteur inverse
	Vec3 oppose();
	

};

