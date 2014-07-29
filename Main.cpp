#include "Scalar.h"

#include "Array.h"
#include "Vector.h"
#include "Matrix.h"

#include "ChessDimensions.h"
#include "ChessPosition.h"

#include "GraphicsRGB.h"
#include "GraphicsArray2D.h"
#include "GraphicsBitmap.h"

#include "LinkedList.h"

#include <iostream>
using namespace std;


void main()
{
	//
	// Linked List test:
	LinkedList<int> L;
	L.append(1);
	L.append(2);
	L.append(4);
	L.append(8);
	for(LLIterator<int> i(L); i.can_continue(); i.next())
	{
		cout << i.value() << endl;
	}


	// END:
	cout << "tada!" << endl;
	char l;
	cin >> l;
}
