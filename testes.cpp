#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Printer{
private:
    string name;
    int avaiblePaper;
public:
    Printer(string name, int paper){
        this->name = name;
        this->avaiblePaper = paper;
    }


    void Print(string txtDoc){
        int requiredPaper = ceil(txtDoc.length() / 10);

        if (requiredPaper > avaiblePaper){
            throw "No papper";
        }


        cout << "Printing: " << txtDoc << endl;
        cout << requiredPaper << " paper used" << endl;
        cout << avaiblePaper << endl;
        avaiblePaper -= requiredPaper;
    }

};


int main(){
    //execption handler

    Printer myPrinter("HP", 10);

    for(int i = 1; i < 13; i++){
        
        try{
            myPrinter.Print("Hello World");
        }
        catch(...){
            cout << "Error:"  << endl;
        }
    }
    // Gneric catch catch(...)


    cin.get();

    return 0;
}