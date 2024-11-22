#include <iostream>
#include <iomanip>


using namespace std;

int main(){
    double a = 0.123456;

    cout << setw(15) << left << a << endl;

    double b =  23.987;

    cout << fixed << setprecision(2) << right << setw(12) << b << endl;

    double c = -123.456;

    cout  << scientific << setprecision(4) << setw(10) << c << endl;

    return 0;
}
