#include "GraphicsBitmap.h"
#include <fstream>
#include <math.h>
using namespace std;


//
// File IO:
inline int Bitmap::row_size()
{
	// rounds 3*width up to a multiple of 4
	// if 3*width is multiple of 4, leaves untouched.
	int too_big = 3*width + 3;
	return too_big - (too_big%4);
}

int Bitmap::read_header_number(ifstream& myfile, int num_bytes)
{
	int value = 0;
	int power = 1;
	char* bytes = new char[num_bytes+1];
	myfile.read(bytes, num_bytes);
	for(int i = 0; i < num_bytes; i++)
	{
		value += power * (bytes[i] & 0xff);
		power <<= 8;
	}
	delete[] bytes;
	bytes = NULL;
	return value;

}

Dimensions Bitmap::read_header(ifstream& myfile)
{
	char B = read_header_number(myfile, 1);
	char M = read_header_number(myfile, 1);
	int size = read_header_number(myfile, 4);
	int reserved = read_header_number(myfile, 4);
	int pixel_offset = read_header_number(myfile, 4);
	int succeeding_header_size = read_header_number(myfile, 4);

	Dimensions new_dimensions;
	new_dimensions.width = read_header_number(myfile, 4);
	new_dimensions.height = read_header_number(myfile, 4);

	int planes = read_header_number(myfile, 2);
	int bits_per_pixel = read_header_number(myfile, 2);
	int compression = read_header_number(myfile, 4);
	int pixel_size = read_header_number(myfile, 4);
	int horizontal_resolution = read_header_number(myfile, 4);
	int vertical_resolution = read_header_number(myfile, 4);
	int colors = read_header_number(myfile, 4);
	int important_colors = read_header_number(myfile, 4);

	return new_dimensions;
}

void Bitmap::read_body(ifstream& myfile)
{
	int rs = row_size();
	char* row = new char[rs];
	for(int r = 0; r < height; r++)
	{
		myfile.read(row, rs); // reads content and padding
		for(int c = 0; c < width; c++) // uses content
		{
			bitmap[r][c].B = (unsigned char) row[3*c+0];
			bitmap[r][c].G = (unsigned char) row[3*c+1];
			bitmap[r][c].R = (unsigned char) row[3*c+2];
		}
	}

	delete[] row;
	row = NULL;
}

void Bitmap::read_from(string filename)
{
	ifstream myfile;
	myfile.open(filename, ios::binary);
	
	// NOTE: ALLOCATE_BITMAP CALLS DEALLOCATE_BITMAP, WHICH USES THE OLD DIMENSIONS.
	// THUS, CAN'T JUST OVERWRITE OLD DIMENSIONS UNTIL AFTER ALLOCATE_BITMAP IS CALLED!
	Dimensions new_dimensions = read_header(myfile);
	allocate_bitmap(new_dimensions.height, new_dimensions.width);
	height = new_dimensions.height;
	width = new_dimensions.width;

	read_body(myfile);

	myfile.close();
}

void Bitmap::write_header_number(ofstream& myfile, int value, int num_bytes)
{
	for(int i = 0; i < num_bytes; i += 1)
	{
		myfile.put(value & 0xff);
		value >>= 8;
	}
}

void Bitmap::write_header(ofstream& myfile)
{
	myfile.put('B');
	myfile.put('M');
	int size = 54 + row_size()*height;
	int reserved = 0;
	int pixel_offset = 54;
	int succeeding_header_size = 40;

	int planes = 1;
	int bits_per_pixel = 24;
	int compression = 0;
	int pixel_size = 3*256*256;
	int horizontal_resolution = 2835;
	int vertical_resolution = 2835;
	int colors = 0;
	int important_colors = 0;
	write_header_number(myfile, size, 4);
	write_header_number(myfile, reserved, 4);
	write_header_number(myfile, pixel_offset, 4);
	write_header_number(myfile, succeeding_header_size, 4);
	write_header_number(myfile, width, 4);
	write_header_number(myfile, height, 4);
	write_header_number(myfile, planes, 2);
	write_header_number(myfile, bits_per_pixel, 2);
	write_header_number(myfile, compression, 4);
	write_header_number(myfile, pixel_size, 4);
	write_header_number(myfile, horizontal_resolution, 4);
	write_header_number(myfile, vertical_resolution, 4);
	write_header_number(myfile, colors, 4);
	write_header_number(myfile, important_colors, 4);
}

void Bitmap::write_body(ofstream& myfile)
{
	int rs = row_size();
	char* row = new char[rs];
		
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			row[3*c+0] = static_cast<int>(bitmap[r][c].B);
			row[3*c+1] = static_cast<int>(bitmap[r][c].G);
			row[3*c+2] = static_cast<int>(bitmap[r][c].R);
		}
		for(int c3 = 3*width; c3 < rs; c3++)
		{
			row[c3] = 0;
		}
		myfile.write(row, rs);
	}
	delete[] row;
	row = NULL;
}

void Bitmap::write_to(string filename)
{
	ofstream myfile;
	myfile.open(filename, ios::binary);

	write_header(myfile);

	write_body(myfile);

	myfile.close();
}


//
// Initializer, Constructors, Destructor, Copier:
void Bitmap::initialize_black()
{
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			bitmap[r][c];
		}
	}
}

Bitmap::Bitmap(int h, int w): Array2D<RGB>::Array2D(h, w)
{
}

Bitmap::Bitmap(string filename):
	Array2D<RGB>::Array2D(32, 32)
{
	read_from(filename);
}

Bitmap::~Bitmap()
{
}


void Bitmap::copy_from(Bitmap &other)
{
	allocate_bitmap(other.height, other.width);

	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			bitmap[r][c] = other[r][c];
		}
	}
}
