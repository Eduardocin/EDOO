#include <iostream>

#include "rectangle.h"

using namespace std;

int main(){
    Rectangle r1(3, 4);
    Rectangle r2(5, 6);

    cout << "Area of r1: " << r1.getArea() << endl;
    cout << "Area of r2: " << r2.getArea() << endl;

    return 0;
}