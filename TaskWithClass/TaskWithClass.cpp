#include <iostream>
#include <string>

class A {

};

class String {
public:
	std::string c_str() {
		return std::string();
	}
	int length() {
		return 0;
	}
	int size() {
		return 0;
	}
	String() {
		std::cout << "Constructor: " << std::endl;
	}
	~String() {
		std::cout << "Destructor: " << std::endl;
	}
private:
	char* m_str;
	size_t m_len;
};
int main()
{
	std::cout << sizeof(A) << std::endl;
	String str;
	return 0;
}

