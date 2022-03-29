#include <iostream>

class Average
{
private:
	int32_t m_sum = 0;
	int8_t m_count = 0;
public:
	Average()
	{

	}

	Average& operator+=(int value);

	friend std::ostream& operator<< (std::ostream& out, const Average& average);
};

Average& Average::operator+=(int value)
{
	m_sum += value;
	++m_count;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Average& average)
{
	out << static_cast<double>(average.m_sum) / average.m_count;

	return out;
}

int main()
{
	Average avg;

	avg += 5;
	std::cout << avg << '\n';

	avg += 9;
	std::cout << avg << '\n';

	avg += 19;
	std::cout << avg << '\n';

	avg += -9;
	std::cout << avg << '\n';

	(avg += 7) += 11;
	std::cout << avg << '\n';

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
