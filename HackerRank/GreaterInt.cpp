#include <iostream>

using namespace std;
/*
*/




inline int greaterInt(const int& a, const int& b, const int& c, const int& d){
    int max = a;
    
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    if(d > max){
        max = d;
    }
    
    return max;
}

int main(){
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << greaterInt(a, b, c, d) << endl;

    return 0;

}