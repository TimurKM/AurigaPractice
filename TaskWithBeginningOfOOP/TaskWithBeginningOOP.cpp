#include <iostream>

class Ball
{
private:
	std::string m_color = "Red";

	double m_radius = 20.0;

public:
	Ball()
	{

	}

	Ball(const std::string& color) : m_color(color)
	{

	}

	Ball(double radius) : m_radius(radius)
	{

	}

	Ball(const std::string& color, double radius) :m_color(color), m_radius(radius)
	{

	}

	void print()
	{
		std::cout << "color: " << m_color << " radius: " << m_radius << std::endl;
	}
};

int main()
{
	Ball def;
	def.print();

	Ball black("black");
	black.print();

	Ball thirty(30.0);
	thirty.print();

	Ball blackThirty("black", 30.0);
	blackThirty.print();

	return 0;
}
