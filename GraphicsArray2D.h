#include <cstdlib>


#ifndef GRAPHICS_ARRAY_2D
#define GRAPHICS_ARRAY_2D

struct Dimensions {int height, width;};

template<class Pixel>
class Array2D: public Dimensions
{
protected:
	Pixel** bitmap;

public:
	Pixel* operator[](int r) // so A[r][c] should be a Pixel.
	{
		return bitmap[r];
	}

	Array2D(int h, int w) {bitmap = NULL; allocate_bitmap(h, w);}
	Array2D(const Array2D& other) {copy_from(other);}
	~Array2D() {deallocate_bitmap();}

	void allocate_bitmap(int h, int w)
	{
		if(height != h || width != w)
		{
			deallocate_bitmap();

			height = h;
			width = w;

			bitmap = new Pixel*[height];
			for(int r = 0; r < height; r++)
			{
				bitmap[r] = new Pixel[width];
			}
		}
	}
	void deallocate_bitmap()
	{
		if(bitmap != NULL)
		{
			for(int r = 0; r < height; r++)
			{
				delete[] bitmap[r];
				bitmap[r] = NULL;
			}
			delete[] bitmap;
			bitmap = NULL;

			height = -1; width = -1;
		}
	}

	void copy_into(Array2D& other)
	{
		other.allocate_bitmap(height, width);
		for(int r = 0; r < height; r++)
		{
			for(int c = 0; c < width; c++)
			{
				other.bitmap[r][c] = bitmap[r][c];
			}
		}
	}
	void copy_from(Array2D& other)
	{
		other.copy_into(*this);
	}
};
#endif
