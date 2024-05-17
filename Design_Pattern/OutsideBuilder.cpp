#include<iostream>


// Class chứa nhiều attribue để khởi tạo
class Product {
private:
	int age;
	std::string name;
	int ID;
public:
	Product() {

	}
	Product(int age, std::string name, int ID) {
		this->age = age;
		this->name = name;
		this->ID = ID;
	}
	void showInfor() {
		std::cout << ID << " " << name << " " << age << std::endl;
	}
};

class ProductBuilder {
public:
	virtual ProductBuilder* setAge(int age) {
		return nullptr;
	};
	virtual ProductBuilder* setName(std::string name) {
		return nullptr;
	}
	virtual ProductBuilder* setId(int id) {
		return nullptr;
	}
	virtual Product build() {
		Product a(0, nullptr, 0);
		return a;
	}

};
class ConcreteBuilder:public ProductBuilder {
	int age;
	int ID;
	std::string name;
public:
	ConcreteBuilder* setAge(int age) {
		this->age = age;
		return this;
	};
	ConcreteBuilder* setName(std::string name) {
		this->name = name;
		return this;
	}
	ConcreteBuilder* setId(int id) {
		this->ID = id;
		return this;
	}
	 Product build() {
		 Product a(this->age, this->name, this->ID);
		return a;
	}

};
int main()
{
	Product a = (new ConcreteBuilder())->setAge(20)->setName("DatCT")->setId(1)->build();
	a.showInfor();
	return 0;
}