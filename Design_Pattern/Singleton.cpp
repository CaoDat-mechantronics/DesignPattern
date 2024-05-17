#include<iostream>

class Singleton {
private:
	
	Singleton() {
	}
public:
	static Singleton& getInstance() {
		static Singleton VALUE;
		Singleton& ref = VALUE;
		return ref;
	}
	
};


int main() {
	Singleton& a = Singleton::getInstance();
	std::cout << &a << std::endl;

	Singleton& b = Singleton::getInstance();
	std::cout << &b << std::endl;
	return 0;
}