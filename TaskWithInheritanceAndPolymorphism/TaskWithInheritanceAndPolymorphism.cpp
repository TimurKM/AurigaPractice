#include <iostream>
#include <memory>
#include <vector>

template <typename T> class Figure
{
public:
	Figure()
	{
		std::cout << "Figure()" << std::endl;
	}
	~Figure()
	{
		std::cout << "~Figure()" << std::endl;
	}

	virtual void what() const = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};

class Square final : public Figure<double>
{
public:
	Square(const double l) : m_length{ l }
	{
		std::cout << "Square()" << std::endl;
	}
	virtual ~Square()
	{
		std::cout << "~Square()" << std::endl;
	}

	void what() const override
	{
		std::cout << "I'm Square" << std::endl;
	}
	double area() const override
	{
		double area = m_length * m_length;
		std::cout << area << std::endl;
		return area;
	}
	double perimeter() const override
	{
		double perimeter = 4 * m_length;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const double m_length;
};

class Rectangle final : public Figure<double>
{
public:
	Rectangle(const double l, const double w) : m_length{ l }, m_width{ w }
	{
		std::cout << "Rectangle()" << std::endl;
	}
	virtual ~Rectangle()
	{
		std::cout << "~Rectangle()" << std::endl;
	}

	void what() const override
	{
		std::cout << "I'm Rectangle" << std::endl;
	}
	double area() const override
	{
		double area = m_length * m_width;
		std::cout << area << std::endl;
		return area;
	}
	double perimeter() const override
	{
		double perimeter = 2 * (m_length + m_width);
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const double m_length;
	const double m_width;
};

class Circle final : public Figure<double>
{
public:
	Circle(const double r) : m_radius{ r }
	{
		std::cout << "Circle()" << std::endl;
	}
	virtual ~Circle()
	{
		std::cout << "~Circle()" << std::endl;
	}

	void what() const override
	{
		std::cout << "I'm Circle" << std::endl;
	}
	double area() const override
	{
		double area = 3.14 * m_radius * m_radius;
		std::cout << area << std::endl;
		return area;
	}
	double perimeter() const override
	{
		double perimeter = 2 * 3.14 * m_radius;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const double m_radius;
};

int main(int argc, char* argv[])
{
	auto s = std::make_shared<Square>(4.);
	auto r = std::make_shared<Rectangle>(2., 3.);
	auto c = std::make_shared<Circle>(5.);

	std::vector<std::shared_ptr<Figure<double>>> v = { s, r, c };

	for (auto& it : v)
	{
		it->what();
		it->area();
		it->perimeter();
	}

	return 0;
}
