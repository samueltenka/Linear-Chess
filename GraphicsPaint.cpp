#include "GraphicsBitmap.h"


void Bitmap::paint_icon(Bitmap& icon, double opacity, int start_r, int start_c)
{
	for(int y = 0; y < icon.height; y++)
	{
		for(int x = 0; x < icon.width; x++)
		{
			bitmap[start_r + y][start_c + x] += icon[y][x] * opacity;
		}
	}
}

void Bitmap::paint_icon(Bitmap& icon, RGB opacities, int start_r, int start_c)
{
	for(int y = 0; y < icon.height; y++)
	{
		for(int x = 0; x < icon.width; x++)
		{
			bitmap[start_r + y][start_c + x] += icon[y][x] * opacities;
		}
	}
}
