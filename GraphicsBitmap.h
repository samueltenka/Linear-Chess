#include "GraphicsRGB.h"
#include "GraphicsArray2D.h"
#include <iostream>
#include <fstream>
using namespace std;


#ifndef GRAPHICS_BITMAP
#define GRAPHICS_BITMAP

class Bitmap: public Array2D<RGB>
{
private:
	void initialize_black();

	int row_size();
	int read_header_number(ifstream& myfile, int num_bytes);
	Dimensions read_header(ifstream& myfile);
	void read_body(ifstream& myfile);

	void write_header_number(ofstream& myfile, int value, int num_bytes);
	void write_header(ofstream& myfile);
	void write_body(ofstream& myfile);
public:
	Bitmap(int h, int w);
	Bitmap(string filename);
	void read_from(string filename);
	void write_to(string filename);
	~Bitmap();

	void paint_icon(Bitmap& icon, double opacity, int start_r, int start_c);
	void paint_icon(Bitmap& icon, RGB opacities, int start_r, int start_c);

	void copy_from(Bitmap &other);
};
#endif
