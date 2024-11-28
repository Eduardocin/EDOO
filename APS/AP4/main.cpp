#include <iostream>
#include "Date.h"

using namespace std;


int main(){
    Date today, anortherdate;

    today.init();

    anortherdate.init(12, 25, 2019);

    cout << "Today is: " << endl;
    today.print();

    cout << "Another date is: " << endl;
    anortherdate.print();

    
    return 0;
}