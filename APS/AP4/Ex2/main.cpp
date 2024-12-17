#include <iostream>
#include "article.h"
#include <string>

using namespace std;


int main() {
    cout << "Esta rodando" << endl;

    Article a1(1, "Artigo 1", 10.0);
    a1.print();
    Article* a2 = new Article(2, "Artigo 2", 20.0);
    a2->print();
    Article* a3 = new Article();
    a3->print();
        
    a1.set_sales_price(15.0);
    a2->set_sales_price(25.0);

    a1.print();
    a2->print();

    delete a2;

    return 0;
}

