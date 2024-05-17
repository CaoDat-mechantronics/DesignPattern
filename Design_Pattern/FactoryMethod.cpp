#include<iostream>

// Abstract product
class Chair {
public:
	virtual void showName() {

	};
};
class PlasticChair : public Chair {
	// Concrete product 1;
public:
	void showName() {
		std::cout << "This is Plastic \n";
	}
};

class WoodChair : public Chair {
	// Concrete product 2
public:
	void showName() {
		std::cout << "This is Wood \n";
	}
};

// Enum to define some type
enum Type {
	PLASTIC, WOOD, NONE
};

// Create a factory class
class Factory {
public:
	static Chair* getChair(Type t) {
		switch (t) {
		case PLASTIC:
			return new PlasticChair();
			break;
		case WOOD:
			return new WoodChair();
			break;
		default:
			std::cout << " Not exist this type \n";
			return nullptr;
			break;
		}
	}
};

int main()
{
	// client to get target object
	Chair* a = Factory::getChair(NONE);
	if (a != nullptr) {
		a->showName();
	}
	
	return 0;
}