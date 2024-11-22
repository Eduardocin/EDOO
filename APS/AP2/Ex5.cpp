#include <iostream>
#include <cstdlib>


using namespace std;


int main(){

    int a;
    cout << "Enter a number: ";
    cin >> a;

    srand(a);
    for(int i = 0; i < 20; i++){
        cout << (rand() % 100) + 1 << endl;
    }

    return 0;
}