#include <iostream>
#include "product.h"


int main(){
    
    Product p1(123456, "Product 1");
    PrepackedFood p2(654321, "Product 2", 1.99);
    FreshFood p3(987654, "Product 3", 1.5, 2.99);

    p1.printer();
    p2.printer();
    p3.printer();
    

    return 0;
}