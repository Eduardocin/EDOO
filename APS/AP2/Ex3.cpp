#include <iostream>

using namespace std;


int main(){

    int i = -2;
    int x = -4 * i++ - 6 % 4;

    cout << x << endl;

    return 0;
}