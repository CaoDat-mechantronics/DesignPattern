#include<iostream>


// Abstract product 1
class Table {
public:
	virtual void showTableName() {
		
	}
};
// concrete product of abstract product 1
class WoodTable : public Table {
public:
	void showTableName() {
		std::cout << "This is WOOD table \n";
	}
};
// Concrete Product from abstract product 1
class PlasticTable : public Table {
public:
	void showTableName() {
		std::cout << "This is Plastic table \n";
	}
};

// Abstract product 2
class Chair {
public:
	virtual void showChairName() {

	}
};
// concrete product of abstract product 2
class WoodChair : public Chair {
public:
	void showChairName() {
		std::cout << "This is WOOD chair \n";
	}
};
// Concrete Product from abstract product 2
class PlasticChair : public Chair {
public:
	void showChairName() {
		std::cout << "This is Plastic chair \n";
	}
};

// Abstract factory
class AbstractFactory {
public:
	virtual Chair* createChair() {
		return nullptr;

	}
	virtual Table* createTable() {
		return nullptr;
	}
};

// Concreate factory 1
class WoodFactory :public AbstractFactory {
public:
	 Chair* createChair() {
		return new WoodChair();
	}
	 Table* createTable() {
		return new WoodTable();

	}
};

// Concreate factory 2
class PlasticFactory :public AbstractFactory {
public:
	Chair* createChair() {
		return new PlasticChair();
	}
	Table* createTable() {
		return new PlasticTable();

	}
};
enum Type {
	PLASTIC, WOOD, NONE
};

// Super Factory
class SuperFactory {
public:
	static AbstractFactory* getFactory(Type t) {
		switch (t)
		{
		case PLASTIC:
			return new PlasticFactory();
			break;
		case WOOD:
			return new PlasticFactory();
			break;
		case NONE:
			std::cout << "No exist this factory \n";
			return nullptr;
			break;
		default:
			break;
		}
	}
};

int main()
{
	// client to call factory
	AbstractFactory* factory = SuperFactory::getFactory(PLASTIC);
	if (factory->createChair() != nullptr &&
		factory->createTable() != nullptr)
	{
		factory->createChair()->showChairName();
		factory->createTable()->showTableName();
	}
	else
	{
		std::cout << "null pointer";
	}
	return 0;
}