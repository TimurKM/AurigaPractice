#include <iostream>
#include <memory>
#include <vector>

template <typename T>
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

	virtual void what() const = 0;
	virtual T area() const = 0;
	virtual T perimeter() const = 0;
};

template <typename T>
class Square final : public Figure<T>
{
public:
	Square(const T l) : m_length{ l }
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
	T area() const override
	{
		T area = m_length * m_length;
		std::cout << area << std::endl;
		return area;
	}
	T perimeter() const override
	{
		T perimeter = 4 * m_length;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const T m_length;
};

template <typename T>
class Rectangle final : public Figure<T>
{
public:
	Rectangle(const T l, const T w) : m_length{ l }, m_width{ w }
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
	T area() const override
	{
		T area = m_length * m_width;
		std::cout << area << std::endl;
		return area;
	}
	T perimeter() const override
	{
		T perimeter = 2 * (m_length + m_width);
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const T m_length;
	const T m_width;
};

template <typename T>
class Circle final : public Figure<T>
{
public:
	Circle(const T r) : m_radius{ r }
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
	T area() const override
	{
		T area = 3.14 * m_radius * m_radius;
		std::cout << area << std::endl;
		return area;
	}
	T perimeter() const override
	{
		T perimeter = 2 * 3.14 * m_radius;
		std::cout << perimeter << std::endl;
		return perimeter;
	}
private:
	const T m_radius;
};

int main(int argc, char* argv[])
{
	auto s = std::make_shared<Square<double>>(4.);
	auto r = std::make_shared<Rectangle<double>>(2., 3.);
	auto c = std::make_shared<Circle<double>>(5.);

	std::vector<std::shared_ptr<Figure<double>>> v = { s, r, c };

	for (auto& it : v)
	{
		it->what();
		it->area();
		it->perimeter();
	}

	return 0;
}
