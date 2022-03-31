#include <iostream>

class IntArray
{
private:
	int m_length = 0;

	int* m_array = nullptr;
public:
	IntArray(int length) : m_length(length)
	{
		if (length > 0)
		{
			m_array = new int[length];
		}
		else
		{
			std::cout << "Length should be positive" << std::endl;
		}

	}

	IntArray(const IntArray& intArray) :m_length(intArray.m_length)
	{
		if (intArray.m_array)
		{
			m_array = new int[m_length];

			for (int i = 0; i < m_length; ++i)
			{
				m_array[i] = intArray.m_array[i];
			}
		}
		else
		{
			m_array = nullptr;
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

	m_length = intArray.m_length;

	if (intArray.m_array)
	{
		m_array = new int[m_length];

		for (int i = 0; i < m_length; ++i)
		{
			m_array[i] = intArray.m_array[i];
		}
	}
	else
	{
		m_array = nullptr;
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
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
