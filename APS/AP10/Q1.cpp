#include <iostream>
#include <string>
using namespace std;



class Node{
    friend class Stack;
    private:
        int data;
        Node* next;
    
    public:
    Node(): data(0), next(nullptr) {}

    Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
    
};



class Stack : public Node {
    private:
        Node* top;
        int size;

    public:
        Stack()
        {
            top = nullptr;
            size = 0;
        }

        ~Stack(){
            while(top != nullptr)
            {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(int data)
        {
            top = new Node(data, top);
            size++;
        }

        int pop()
        {
            if(top == nullptr)
            {
                return -1;
            }

            int temp = top->data;
            top = top->next;
            size--;
            return temp;
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
                cout << s.pop() << endl;
            }
        }
    }

    return 0;
}