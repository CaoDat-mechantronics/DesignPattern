#include<iostream>

class Product {
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
	class Builder {
		int Bage;
		std::string Bname;
		int BID;
	public:
		Builder* setAge(int age) {
			this->Bage = age;
			return this;
		};
		Builder* setName(std::string val) {
			this->Bname = val;
			return this;
		}
		Builder* setId(int id) {
			this->BID = id;
			return this;
		}
		Product build() {
			Product a(this->Bage, this->Bname, this->BID);
			return a;
		}
	};
	
	void showInfor() {
		std::cout << ID << " " << name << " " << age << std::endl;
	}
};

int main()
{
	Product a = (new Product::Builder())->setAge(20)->setName("dat")->setId(2)->build();
	a.showInfor();
	return 0;
}