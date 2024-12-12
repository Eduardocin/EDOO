#include <iostream>

#include "fraction.h"

using namespace std;


int main(){
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3;
    f3 = f1 + f2;
    cout << f3 << endl;
    f3 = f1 - f2;
    cout << f3 << endl;
    f3 = f1 * f2;
    cout << f3 << endl;
    f3 = f1 / f2;
    cout << f3 << endl;
    f3 = f1++;
    cout << f3 << endl;
    f3 = f1--;
    cout << f3 << endl;
    return 0;


}