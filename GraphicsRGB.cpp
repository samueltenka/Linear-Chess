#include "GraphicsRGB.h"
#include "GraphicsRGB.h"


//
// Constructors and Copy:
RGB::RGB()
{
	R = G = B = 0;
}
RGB::RGB(val r, val g, val b):
	R(r), G(g), B(b)
{
}
RGB::RGB(const RGB& other)
{
	(*this) = other;
}
RGB& RGB::operator=(const RGB& other) // copy
{
	R = other.R;
	G = other.G;
	B = other.B;
	return *this;
}

//
// Operators with Assignment:
RGB& RGB::operator+=(const RGB& other)
{
	R += other.R;
	G += other.G;
	B += other.B;
	return *this;
}
RGB& RGB::operator-=(const RGB& other)
{
	R -= other.R;
	G -= other.G;
	B -= other.B;
	return *this;
}
RGB& RGB::operator*=(const RGB& other)
{
	R *= other.R;
	G *= other.G;
	B *= other.B;
	return *this;
}
RGB& RGB::operator*=(double scale)
{
	R *= scale;
	G *= scale;
	B *= scale;
	return *this;
}
RGB& RGB::operator/=(double scale)
{
	R /= scale;
	G /= scale;
	B /= scale;
	return *this;
}

//
// Operators without Assignment:
RGB RGB::operator+(const RGB& other) const {return (RGB(*this) += other);}
RGB RGB::operator-(const RGB& other) const {return (RGB(*this) -= other);}
RGB RGB::operator*(const RGB& other) const {return (RGB(*this) *= other);}
RGB RGB::operator*(double scale) const {return (RGB(*this) *= scale);}
RGB RGB::operator/(double scale) const {return (RGB(*this) /= scale);}

//
// Bound:
void RGB::bound()
{
	R = R < 0 ? 0 : R > 255 ? 255 : R;
	G = G < 0 ? 0 : G > 255 ? 255 : G;
	B = B < 0 ? 0 : B > 255 ? 255 : B;
}
