#include <iostream>
#include <string>

using namespace std;

inline void swap_firstchar(string& a, string& b){
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
}

int main(){
    size_t size_a, size_b;
    string a, b;

    cin >> a >> b;

    size_a = a.size();
    size_b = b.size();


    swap_firstchar(a, b);

    cout << size_a << " " << size_b << endl;
    cout << a + b << endl;
    
    cout << a << " " << b ;



    return 0;
}