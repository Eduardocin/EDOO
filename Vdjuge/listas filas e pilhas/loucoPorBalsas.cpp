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

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = new Node();
        size = 0;
    }

    ~Queue() {
        while (front != nullptr)
        {
            Node* temp = front;
            front = front->getNext();
            delete temp;

        }
    }

    void enqueue(int value) {
        rear->setNext(new Node(value));
        rear = rear->getNext();
        size++;
    }

    int dequeue() {
        if (size == 0)
        {
            return -1;
        }

        Node* temp = front->getNext();
        int val = temp->getData();

        front->setNext(temp->getNext());

        if (front->getNext() == nullptr) {
            rear = front;
        }

        size--;
        delete temp;
        return val;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return front->getNext()->getData();
    }

    bool isEmpty() const {
        return size == 0;
    }

};




int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();
    int caseNum = 1;
    while (numCases--)
    {
        Queue* q = new Queue[2];
        string ferrySide = "left", carSide, initialSideCar;
        int ferryLength, carLength, numCars, capacity, count = 0;

        cin >> ferryLength >> numCars;
        cin.ignore();
        ferryLength *= 100;

        for (int i = 0; i < numCars; i++) {
            cin >> carLength >> carSide;
            if (i == 0) {
                initialSideCar = carSide;
            }
            if (carSide == "esquerdo") {
                q[0].enqueue(carLength);
            }
            else {
                q[1].enqueue(carLength);
            }
        }


        while (!q[0].isEmpty() || !q[1].isEmpty())
        {

            if (ferrySide == "left")
            {
                capacity = ferryLength;
                while (!q[0].isEmpty() && (q[0].getFront() < capacity))
                {
                    capacity -= q[0].dequeue();
                }
                ferrySide = "right";
            }
            else
            {
                capacity = ferryLength;
                while (!q[1].isEmpty() && (q[1].getFront() < capacity))
                {
                    capacity -= q[1].dequeue();
                }
                ferrySide = "left";
            }
            count++;
        }

        cout << "Caso " << caseNum << ": " << count << endl;
        caseNum++;
        delete[] q;
    }

    return 0;
}