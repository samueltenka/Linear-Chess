#ifndef GRAPHICS_RGB
#define GRAPHICS_RGB

typedef double val;

class RGB
{
	friend class Bitmap;

public:
	val R, G, B;

public:
	RGB();
	RGB(val r, val g, val b);
	RGB::RGB(const RGB& other);

	RGB& operator=(const RGB& other);

	RGB& operator+=(const RGB& other);
	RGB& operator-=(const RGB& other);
	RGB& operator*=(const RGB& other); // component-wise: (rR, gG, bB)
	RGB& operator*=(double scale);
	RGB& operator/=(double scale);

	RGB operator+(const RGB& other) const;
	RGB operator-(const RGB& other) const;
	RGB operator*(const RGB& other) const; // component-wise: (rR, gG, bB)
	RGB operator*(double scale) const;
	RGB operator/(double scale) const;

	void bound();
};
#endif
