#ifndef ARRAY
#define ARRAY

template<typename T>
class Array
{
private:
	T* data;

public:
	const int length;

	Array(int l):
		length(l)
	{
		data = new T[l];
	}
	Array()
	{
	}

	T& operator[](int i) // by reference, so both gets and sets.
	{
		return data[i];
	}

	~Array()
	{
		delete[] data;
	}
};
#endif
