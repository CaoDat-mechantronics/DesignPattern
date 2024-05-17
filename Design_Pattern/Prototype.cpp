#include<iostream>

// Prototype interface
class Prototype {
public:
	virtual Prototype* clone() {
		return nullptr;
	}
};

class Human : public Prototype {
private:
	int Data;

public:
	Human(int value) {
		this->Data = value;
	}
	Human* clone() {
		return new Human(this->Data);
	}
	int getData() {
		return this->Data;
	}

};

int main()
{
	Human* a = new Human(3);
	std::cout << "Value is  " << a->getData() <<std::endl;
	Human* b = a->clone();
	std::cout << " cloned object" << std::endl;
	std::cout << "Value is  " << b->getData() <<std::endl;


}