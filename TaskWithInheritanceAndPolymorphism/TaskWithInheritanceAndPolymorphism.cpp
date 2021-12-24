#include <iostream>
#include <memory>
#include <vector>

class Figure
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

	virtual const void what() = 0;
	virtual const double area() = 0;
	virtual const double perimeter() = 0;
};

class Square final : public Figure
{
public:
	Square(const double l)
	{
		m_length = l;
		std::cout << "Square()" << std::endl;
	}
	virtual ~Square()
	{
		std::cout << "~Square()" << std::endl;
	}

	void const what() override
	{
		std::cout << "I'm Square" << std::endl;
	}
	double const area() override
	{
		double area = m_length * m_length;
		std::cout << area << std::endl;
		return area;
	}
	double const perimeter() override
	{
		double perimeter = 4 * m_length;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	double m_length;
};

class Rectangle final : public Figure
{
public:
	Rectangle(const double l, const double w)
	{
		m_length = l;
		m_width = w;
		std::cout << "Rectangle()" << std::endl;
	}
	virtual ~Rectangle()
	{
		std::cout << "~Rectangle()" << std::endl;
	}

	void const what() override
	{
		std::cout << "I'm Rectangle" << std::endl;
	}
	double const area() override
	{
		double area = m_length * m_width;
		std::cout << area << std::endl;
		return area;
	}
	double const perimeter() override
	{
		double perimeter = 2 * (m_length + m_width);
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	double m_length;
	double m_width;
};

class Circle final : public Figure
{
public:
	Circle(const double r)
	{
		m_radius = r;
		std::cout << "Circle()" << std::endl;
	}
	virtual ~Circle()
	{
		std::cout << "~Circle()" << std::endl;
	}

	void const what() override
	{
		std::cout << "I'm Circle" << std::endl;
	}
	double const area() override
	{
		double area = 3.14 * m_radius * m_radius;
		std::cout << area << std::endl;
		return area;
	}
	double const perimeter() override
	{
		double perimeter = 2 * 3.14 * m_radius;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	double m_radius;
};

int main(int argc, char* argv[])
{
	auto s = std::make_shared<Square>(4.);
	auto r = std::make_shared<Rectangle>(2., 3.);
	auto c = std::make_shared<Circle>(5.);

	std::vector<std::shared_ptr<Figure>> v = { s, r, c };

	for (auto& it : v)
	{
		it->what();
		it->area();
		it->perimeter();
	}

	return 0;
}
