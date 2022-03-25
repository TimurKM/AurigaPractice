#include <iostream>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denomimator = 1;

public:
	void print()
	{
		std::cout << m_numerator << "/" << m_denomimator << std::endl;
	}

	int nod(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}

	void reduce()
	{
		int nod = Fraction::nod(m_numerator, m_denomimator);
		m_numerator /= nod;
		m_denomimator /= nod;
	}

	friend Fraction operator*(const Fraction& f, int value);
	friend Fraction operator*(int value, const Fraction& f);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);

	Fraction(int numerator = 0, int denomimator = 1) :
		m_numerator(numerator), m_denomimator(denomimator)
	{
		reduce();
	}
};

Fraction operator*(const Fraction& f, int value)
{
	int numerator = f.m_numerator * value;

	return Fraction(numerator, f.m_denomimator);
}

Fraction operator*(int value, const Fraction& f)
{
	int numerator = f.m_numerator * value;

	return Fraction(numerator, f.m_denomimator);
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	int numerator = f1.m_numerator * f2.m_numerator;

	int denomimator = f1.m_denomimator * f2.m_denomimator;

	return Fraction(numerator, denomimator);
}

int main()
{
	Fraction f1(3, 4);
	f1.print();

	Fraction f2(2, 7);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 3;
	f4.print();

	Fraction f5 = 3 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();
}
