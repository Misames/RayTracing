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

	Vec3 normalized();
	float norm();
	float dot(Vec3 vec);
	float dot(Point vec);
	Vec3 oppose();
	

};

