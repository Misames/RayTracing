#pragma once


class Hvec3
{
public:
	float x;
	float y;
	float z;
	float w = 0;

public:

	Hvec3();
	Hvec3(float a, float b, float c);
	

	Hvec3& operator*= (const float a);
	Hvec3& operator+= (const float a);
	Hvec3& operator-= (const float a);
	Hvec3& operator/= (const float a);

	Hvec3 normalized();
	float norm();
	float dot(Hvec3 vec);
	Hvec3 oppose();
	

};
