#include "Color.h"

Color::Color() {
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::Color(const float R, const float G, const float B) {
	this->r = R;
	this->g = G;
	this->b = B;
}

Color::Color(const Color& col) {
	this->r= col.r;
	this->g = col.g;
	this->b = col.b;
}

Color Color::operator*(Color c) const {
	Color ret;
	ret.r = this->r * c.r;
	ret.g = this->g * c.g;
	ret.b = this->b * c.b;
}