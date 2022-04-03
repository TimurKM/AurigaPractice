#include <iostream>
#include <ostream>
#include <fstream>

class Fraction
{
private:
	int m_numerator = 0;
	int m_denomimator = 1;

public:
	void print() const
	{
		std::cout << m_numerator << "/" << m_denomimator << std::endl;
	}

	int nod(int a, int b) const
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}

	void reduce()
	{
		int searchingNod = nod(m_numerator, m_denomimator);
		m_numerator /= searchingNod;
		m_denomimator /= searchingNod;
	}

	friend Fraction operator*(const Fraction& f, int value);
	friend Fraction operator*(int value, const Fraction& f);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);

	friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
	friend std::istream& operator>> (std::istream& in, Fraction& f);

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

std::ostream& operator<< (std::ostream& out, const Fraction& f)
{
	out << f.m_numerator << "/" << f.m_denomimator;

	return out;
}

std::istream& operator>> (std::istream& in, Fraction& f)
{
	char c = ' ';

	in >> f.m_numerator;
	in >> c;
	in >> f.m_denomimator;

	f.reduce();

	return in;
}

using userFraction = const Fraction&;

void resultPrint(userFraction f1, userFraction f2, std::ostream& destination)
{
	destination << f1 << " * " << f2 << " is " << f1 * f2 << std::endl;
}

void printInConsole(userFraction f1, userFraction f2)
{
	resultPrint(f1, f2, std::cout);
}

void writeInFile(userFraction f1, userFraction f2)
{
	std::ofstream output_file("Test1.txt");

	resultPrint(f1, f2, output_file);
}

void selectWayOfWriting(userFraction f1, userFraction f2, void (*wayPtr)(userFraction f1, userFraction f2) = printInConsole)
{
	if (wayPtr)
	{
		wayPtr(f1, f2);
	}
	else
	{
		std::cout << "WayPtr is nullptr" << std::endl;
	}
}

void getUserInput(Fraction& f1, Fraction& f2, int& userChoice)
{
	std::cout << "Enter fraction 7: ";
	std::cin >> f1;

	std::cout << "Enter fraction 8: ";
	std::cin >> f2;

	std::cout << "Input 1 or 2: " << std::endl;

	std::cin >> userChoice;
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

	Fraction f7;

	Fraction f8;

	auto userChoice = 0;

	void (*fcnPtr)(userFraction f1, userFraction & f2) = nullptr;

	getUserInput(f7, f8, userChoice);

	if (userChoice == 1)
	{
		fcnPtr = printInConsole;
	}
	else if (userChoice == 2)
	{
		fcnPtr = writeInFile;
	}

	selectWayOfWriting(f7, f8, fcnPtr);
}
