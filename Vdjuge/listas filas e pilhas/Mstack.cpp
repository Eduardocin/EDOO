#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

    int getData() const {
        return data;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }

};


class Stack {
private:
    Node* top;
    int size;

public:
    Stack(Node* top = nullptr, int size = 0) : top(top), size(size) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

    void push(int value) {
        top = new Node(value, top);
        size++;
    }

    int pop() {
        if (top == nullptr) {
            return -1;
        }

        Node* temp = top;
        int val = top->getData();
        top = top->getNext();

        size--;
        delete temp;
        return val;
    }

    int getMax() {
        if(top == nullptr){
            return -1;
        }


        int max = top->getData();
        Node* temp = top->getNext();
        while (temp != nullptr)
        {
            int val_temp = temp->getData();
            if (val_temp > max)
            {
                max = val_temp;
            }
            temp = temp->getNext();
        }
        return max;
    }


    int getMin() {
        if(top == nullptr){
            return -1;
        }

        int min = top->getData();
        Node* temp = top->getNext();
        while (temp != nullptr)
        {
            int val_temp = temp->getData();
            if (val_temp < min)
            {
                min = val_temp;
            }
            temp = temp->getNext();
        }
        return min;
    }


};


int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();

    string comando;
    int valor;
    Stack* s = new Stack();
    while (numCases--) {
        cin >> comando;
        if (comando == "push") {
            cin >> valor;
            s->push(valor);
        }
        else if (comando == "getMax")
        {
            int maxVal = s->getMax();
            if(maxVal == -1){
                cout << "empty stack" << endl;
            }
            else{
                cout << maxVal << endl;
            }
        }
        else if (comando == "getMin")
        {
            int min = s->getMin();
            if(min == -1){
                cout << "empty stack" << endl;
            }
            else{
                cout << min << endl;
            }
        }
        else {
            int popVal = s->pop();
            if(popVal == -1){
                cout << "empty stack" << endl;
            }
            else{
                cout << popVal << endl;
            }
        }
    }

    return 0;
}