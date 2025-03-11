//// filepath: /C:/Users/Eduar/OneDrive/Documentos/GitHub/EDOO/Vjudge/Lista1/B.cpp
#include <iostream>
#include <string>

using namespace std;

class Node {

private:
    char data;
    Node* next;
public:
    Node(char data = '\0', Node* next = nullptr) : data(data), next(next) {}

    char getData() const {
        return data;
    }
    
    Node* getNext() const {
        return next;
    }

};

class Stack {
private:
    Node* top;
    int size;
public:
    Stack() : top(nullptr), size(0) {}

    ~Stack(){
        while(top != nullptr){
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

    void push(char data){
        top = new Node(data, top);
        size++;
    }

    char pop(){
        if(top == nullptr){
            return '\0';
        }
        Node* temp = top;
        top = top->getNext();
        char data = temp->getData();
        delete temp;
        size--;
        return data;
    }

    int getSize() const {
        return size;
    }
};

int main(){
    string str;
    int numberCases;
    cin >> numberCases;
    cin.ignore();

    while(numberCases--){
        getline(cin, str);
        Stack* stack = new Stack();
        bool valid = true;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '[')
            {
                stack->push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']')
            {
                char c = stack->pop();
                if(c == '\0'){
                    valid = false;
                    break;
                }
                if((c == '(' && str[i] != ')') || (c == '[' && str[i] != ']'))
                {
                    valid = false;
                    break;
                }
            }
        }

        if(valid && stack->getSize() == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

        delete stack;
    }

    return 0;
}