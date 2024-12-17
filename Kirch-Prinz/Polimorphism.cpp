#include <iostream>

using namespace std;

class Animal{
public:
    virtual void sound() = 0;
};

class Dog : public Animal{
    public:
        Dog(){
            cout << "Dog constructor" << endl;
        };

        void sound() override{
            cout << "Woof" << endl;
        };
};

int main(){
    Dog d;
    d.sound();
    return 0;
}