#include <iostream>
#include <string>
#include "product.h"


using namespace std;


// Implementation of Product class
Product::Product(long barcode, string name): barcode(barcode), name(name) {};


//Getters
long Product::getBarcode() const {return barcode;}
string Product::getName() const {return name;}

//Setters
void Product::setBarcode(long& barcode) {this->barcode = barcode;}
void Product::setName(string name) {this->name = name;}


void Product::scanner() {
    cout << "Enter barcode: ";
    cin >> barcode;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
}

void Product::printer() const {
    cout << "Barcode: " << barcode << ", Name: " << name << endl;
}

// Implementation of PrepackedFood class
PrepackedFood::PrepackedFood(long barcode, string name, double unitPrice): Product(barcode, name), unitPrice(unitPrice) {};

//Getters
double PrepackedFood::getUnitPrice() const {return unitPrice;}
void   PrepackedFood::setUnitPrice(double unitPrice) {this->unitPrice = unitPrice;}

void PrepackedFood::printer() const {
    cout << "Unit price: " << unitPrice << endl;
}


// Implementation of FreshFood class

FreshFood::FreshFood(long barcode, string name, double weight, double pricePerKilo): Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {};

//Getters
double FreshFood::getWeight() const {return weight;}
double FreshFood::getPricePerKilo() const {return pricePerKilo;}


//Setters
void FreshFood::setWeight(double weight) {this->weight = weight;}
void FreshFood::setPricePerKilo(double pricePerKilo) {this->pricePerKilo = pricePerKilo;}

double FreshFood::calculatePrice() const {
    return weight * pricePerKilo;
}

void FreshFood::printer() const {
    cout << "Weight: " << weight << ", Price per kilo: " << pricePerKilo << endl;
}

