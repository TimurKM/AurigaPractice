#include <iostream>

class IntArray
{
private:
	size_t m_length = 0;

	int* m_array = nullptr;
public:
	IntArray(size_t length) : m_length(length)
	{
		try
		{
			m_array = new int[m_length];
		}
		catch (std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}

	}

	IntArray(const IntArray& intArray) :m_length(intArray.m_length)
	{
		try
		{
			m_array = new int[m_length];

			memcpy(m_array, intArray.m_array, sizeof(m_array[0]) * m_length);
		}
		catch (const std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}
	}

	~IntArray()
	{
		delete[] m_array;
	}

	IntArray& operator= (const IntArray& intArray);

	int& operator[] (const int index);

	friend std::ostream& operator<< (std::ostream& out, const IntArray& intArray);
};

IntArray& IntArray::operator= (const IntArray& intArray)
{
	if (this == &intArray)
	{
		return *this;
	}

	delete[] m_array;

	m_array = nullptr;

	m_length = intArray.m_length;

	if (intArray.m_array != nullptr)
	{
		m_array = new int[m_length];

		for (int i = 0; i < m_length; ++i)
		{
			m_array[i] = intArray.m_array[i];
		}
	}

	return *this;
}

int& IntArray::operator[] (const int index)
{
	if (index >= 0 && index < m_length)
	{
		return m_array[index];
	}
	else
	{
		std::cout << "Index out of range" << std::endl;
	}
}

std::ostream& operator<< (std::ostream& out, const IntArray& intArray)
{
	for (int i = 0; i < intArray.m_length; ++i)
	{
		std::cout << intArray.m_array[i] << ' ';
	}

	return out;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;

	return a;
}

int main()
{
	IntArray a = fillArray();

	std::cout << a << std::endl;

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << std::endl;

	return 0;
}
