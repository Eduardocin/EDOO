#include <iostream>
#include <cstring> // For strcpy

class Person {
    char* name; // Dynamically allocated memory
    int age;

public:
    // Constructor
    Person(const char* name, int age) {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        std::cout << "Constructor called for " << this->name << std::endl;
    }
    

    // Copy constructor
    Person(const Person& other) {
        age = other.age;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        std::cout << "Copy constructor called for " << name << std::endl;
    }

    // Destructor
    ~Person() {
        std::cout << "Destructor called for " << name << std::endl;
        delete[] name;
    }

    // Function to display details
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person person1("Alice", 25);    // Constructor is called
    person1.display();

    Person person2 = person1;      // Copy constructor is called
    person2.display();

    return 0;
}
