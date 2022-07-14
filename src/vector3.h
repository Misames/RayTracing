
class vecteur
{
public:
	float x;
	float y;
	float z;
	
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

