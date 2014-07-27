#include <cstdlib> // for NULL


#ifndef ARRAY
#define ARRAY
template<typename T>
class Array
{
protected:
	T* data;
	int length;

public:
	//
	// for declaring w/o immediate initialization:
	Array()
	{
		data = NULL;
	}
	void initialize(int l)
	{
		if(data == NULL) // "initialize" only works once
		{
			length = l;
			data = new T[l];
		}
	}

	//
	// for immediate initialization:
	Array(int l):
		length(l)
	{
		data = new T[l];
	}

	T& operator[](int r) const
	{
		return data[r];
	}

	~Array()
	{
		delete[] data;
	}
};
#endif
