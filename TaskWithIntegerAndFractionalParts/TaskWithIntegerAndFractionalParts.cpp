#include <iostream>
#include <cstdint>

class FixedPoint
{
private:
	std::int16_t m_integerPart = 0.0;

	std::int8_t m_fractionalPart = 0.0;
public:
	FixedPoint(std::int16_t integerPart = 0, std::int8_t fractionalPart = 0) :
		m_integerPart(integerPart), m_fractionalPart(fractionalPart)
	{
		if (m_integerPart < 0.0 || m_fractionalPart < 0.0)
		{
			if (m_integerPart > 0.0)
			{
				m_integerPart = -m_integerPart;
			}

			if (m_fractionalPart > 0.0)
			{
				m_fractionalPart = -m_fractionalPart;
			}

		}
	}

	FixedPoint(double d)
	{
		m_integerPart = static_cast<int16_t>(d);

		m_fractionalPart = static_cast<std::int8_t>(round((d - m_integerPart) * 100));
	}

	operator double() const
	{
		return m_integerPart + static_cast<double>(m_fractionalPart) / 100;
	}

	friend std::ostream& operator<< (std::ostream& out, const FixedPoint& fixedPoint);

	friend std::istream& operator>> (std::istream& in, FixedPoint& fixedPoint);

	friend bool operator==(const FixedPoint& fp1, const FixedPoint& fp2);

	friend FixedPoint operator+(const FixedPoint& fp1, const FixedPoint& fp2);

	FixedPoint operator-()
	{
		return FixedPoint(-m_integerPart, -m_fractionalPart);
	}
};

std::ostream& operator<< (std::ostream& out, const FixedPoint& fixedPoint)
{
	out << static_cast<double>(fixedPoint);

	return out;
}

std::istream& operator>> (std::istream& in, FixedPoint& fixedPoint)
{
	auto d = 0.0;
	in >> d;
	fixedPoint = FixedPoint(d);

	return in;
}

bool operator==(const FixedPoint& fp1, const FixedPoint& fp2)
{
	return (fp1.m_integerPart == fp2.m_integerPart && fp1.m_fractionalPart == fp2.m_fractionalPart);
}

FixedPoint operator+(const FixedPoint& fp1, const FixedPoint& fp2)
{
	return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
}

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << std::endl; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << std::endl; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << std::endl; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << std::endl; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << std::endl; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << std::endl; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << std::endl; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << std::endl; // первое значение отрицательное, возможно переполнение
}

int main()
{
	FixedPoint a(37, 58);
	std::cout << a << std::endl;

	FixedPoint b(-3, 9);
	std::cout << b << std::endl;

	FixedPoint c(4, -7);
	std::cout << c << std::endl;

	FixedPoint d(-5, -7);
	std::cout << d << std::endl;

	FixedPoint e(0, -3);
	std::cout << e << std::endl;

	SomeTest();

	FixedPoint f(-0.48);
	std::cout << f << std::endl;

	std::cout << -f << std::endl;

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> f;

	std::cout << "You entered: " << f << std::endl;

	return 0;
}
