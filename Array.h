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
