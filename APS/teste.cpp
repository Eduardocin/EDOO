#include <iostream>

using namespace std;

class Animal {
public:
	virtual void sound() = 0;  // Pure virtual function  
};

class Dog : public Animal {
public:
	void sound() override {
		std::cout << "Woof\n";
	}
};

class Cat : public Animal {
public:
	void sound() override {
		std::cout << "Meow\n";
	}
};

int main() {
	Animal* myDog = new Dog();
	Animal* myCat = new Cat();

	myDog->sound();  // Outputs: Woof  
	myCat->sound();  // Outputs: Meow  

	delete myDog;
	delete myCat;
	return 0;
}