#include <iostream>
#include <string>
using namespace std;



class Node{
    private:
        int data;
        Node* next;
    
    public:
        Node(int data, Node* next): data(data), next(next) {}
        
        // Getters
        int getData() const {
            return data;
        }

        Node* getNext() const {
            return next;
        }
        
        void setNext(Node* next){
            this->next = next;
        }
};


class Stack {
    private:
        Node* top;
        int size;

    public:
        Stack() : top(nullptr), size(0) {}

        
        ~Stack(){
            while(top != nullptr)
            {
                Node* temp = top;
                top = top->getNext();
                delete temp;
            }
        }

        void push(const int data)
        {
            top = new Node(data, top);
            size++;
        }

        int pop(int count)
        {
            if(top == nullptr)
            {
                return -1;
            }

            int sum = 0;
            while(count --)
            {
                sum += top->getData();
                Node* toDelete = top;
                top = top->getNext();
                size--;
    
                delete toDelete;
            }

            return sum;
        }

        int getSize() const
        {
            return size;
        }
};


int main() {

    int cases, value;
    string op;
    Stack s;

    cin >> cases;
    cin.ignore();
    

    while(cases--){
        cout << "Caso " << cases + 1 << ":" << endl;
        while(op != "end"){
            cin >> op;
            if(op == "push"){
                cin >> value;
                s.push(value);
            }
            else if(op == "pop"){
                int count;
                cin >> count;
                cout << s.pop(count) << endl;
            }
        }
    }

    return 0;
}