#include <iostream>
#include <cmath>
using namespace std;

void increment(int* a, int* b){
    
    int temp = *a;
    *a = *a + *b;
    *b = abs(*b - temp);
}



int main(){
    int a, b;

    cin >> a >> b;

    increment(&a, &b);
    cout << a << endl << b;


    return 0;
}