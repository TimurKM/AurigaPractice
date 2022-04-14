#include <iostream> 
#include <stdexcept>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;
public:
	Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
	{
		if (denominator == 0)
		{
			throw std::runtime_error("Invalid denominator");
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
};

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << "Fraction(" << fraction.m_numerator << "/" << fraction.m_denominator << ")";

	return out;
}

int main()
{
	std::cout << "Enter numerator: ";
	int numerator;
	std::cin >> numerator;

	std::cout << "Enter denominator: ";
	int denominator;
	std::cin >> denominator;

	try
	{
		Fraction fraction(numerator, denominator);
		std::cout << fraction;
	}
	catch (std::exception&)
	{
		std::cout << "Your fraction has an invalid denominator" << std::endl;
	}

	return 0;
}
