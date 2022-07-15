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

	float norm();
	float dot(Point vec);
	Point oppose();
	Point normalized();

};

