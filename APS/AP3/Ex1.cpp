#include <iostream>
#include <string.h>

using namespace std;

int main(){

    string s1("As time by ...");
    string s2("goes");

    cout << s1 << endl; 
    // insert s2 in front of by
    s1.insert(11, s2);
    s1 = s1.substr(0, 10);
    // replace tiem with bill
    s1.replace(3, 4, "bill");

    cout << s1 << endl;

    return 0;
}