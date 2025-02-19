#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int data = -1, Node* next= nullptr) : data(data), next(next) {}

    int getData() const {
        return data;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }


};


class Queue {
private:
    Node* front;
    Node* rear;
    int size, solved;

public:
    Queue() {
        front = rear = new Node();
        size = solved = 0;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->getNext();
            delete temp;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        rear->setNext(newNode);
        rear = rear->getNext();
        size++;
    }

    int dequeue() {
        if (size == 0) {
            return -1;
        }

        Node* temp = front->getNext();
        int val = front->getNext()->getData();
        front->setNext(front->getNext()->getNext());

        if (front->getNext() == nullptr) {
            rear = front;
        }

        size--;
        solved++;
        return val;
    }

    void print() {
        if (size == 0) {
            cout << "x" << endl;
            return;
        }

        Node* temp = front->getNext();
        while (temp != nullptr) {
            int val = temp->getData();
            cout << val << " ";
            temp = temp->getNext();
        }
        cout << endl;
        return;
    }   

    void getStatus() {
        cout << solved << " " << size << endl;
    }
};



int main() {
    string input;
    int value, solved;
    Queue q;


    while ((cin >> input && input != "end")) {
        cin.ignore();
        if (input == "add")
        {
            cin >> value;
            q.enqueue(value);
        }
        else if (input == "solve")
        {
            q.dequeue();
        }
        else if (input == "print")
        {
            q.print();
        }
        else if (input == "stats")
        {
            q.getStatus();
        }

    }


    return 0;
}