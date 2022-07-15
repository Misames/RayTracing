#pragma once
#include <cmath>
class Point 
{
public :
	float x;
	float y;
	float z;

public :
	Point();
	Point(float a, float b, float c);
	Point(const Point& p);
	Point& operator*= (const float a);
	Point& operator+= (const float a);
	Point& operator- (const float a);
	Point& operator/= (const float a);
	float& operator[](const int i);
	float operator[](const int i)const;
	Point& operator-(const Point p);
	//renvoie la norme du point
	float norm();
	//renvoie le scalaire du point avec le point passé en parametre
	float dot(Point vec);
	//renvoie l'inverse du point
	Point oppose();
	//renvoie le point normalisé
	Point normalized();

};

