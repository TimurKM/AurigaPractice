#include <iostream> 
#include <initializer_list> 

class ArrayInt
{
private:
	int m_length = 0;

	int* m_data = nullptr;

public:
	ArrayInt() = default;

	ArrayInt(int length) :m_length(length)
	{
		try
		{
			m_data = new int[m_length];
		}
		catch (std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}

	}

	ArrayInt(const std::initializer_list<int>& list) :ArrayInt(list.size())
	{
		auto count = 0;

		for (auto& element : list)
		{
			m_data[count] = element;

			++count;
		}
	}

	~ArrayInt()
	{
		delete[] m_data;
	}

	int& operator[](int index) const
	{
		if (index >= 0 && index < m_length)
		{
			return m_data[index];
		}
		else
		{
			std::cout << "Index out of range" << std::endl;
		}
	}

	int getLength() const
	{
		return m_length;
	}

	ArrayInt& operator= (const ArrayInt& arrayInt);
};

void print(const ArrayInt& arrayInt)
{
	for (auto count = 0; count < arrayInt.getLength(); ++count)
	{
		std::cout << arrayInt[count] << ' ';
	}
}

ArrayInt& ArrayInt::operator=(const ArrayInt& arrayInt)
{
	if (m_data != nullptr)
	{
		delete[] m_data;

		m_data = nullptr;
	}

	m_length = arrayInt.m_length;

	m_data = new int[arrayInt.m_length];

	memcpy(m_data, arrayInt.m_data, sizeof(m_data[0]) * m_length);

	return *this;
}
int main()
{
	ArrayInt array{ 7, 6, 5, 4, 3, 2, 1 };

	print(array);

	array = { 1, 4, 9, 12, 15, 17, 19, 21 };

	std::cout << std::endl;

	print(array);

	return 0;
}
