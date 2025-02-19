#include <iostream>
#include <string>
#include <utility>

using namespace std;


class Node{
    private:
        pair<int, string> data;
        Node* next;
    public:
        Node(pair<int,string> data = pair<int, string>(-1, "Dummy"), Node* next = nullptr) : data(data), next(next){}
        
        pair<int, string> getData() const {return data;}
        Node* getNext() const {return next;}

        
        void setNext(Node* next) {this->next = next;}

};


class Queue{  
    Node* front;
    Node* rear;
    int size;

    public:
        Queue(){
            front = rear = new Node();
            size = 0;
        }

        ~Queue(){
            while(front != nullptr){
                Node* temp = front;
                front = front->getNext();
                delete temp;
            }
        }

        void enqueue(pair<int, string> value){ 
            rear->setNext(new Node(value));
            rear = rear->getNext();
            size++;
        }

        pair<int, string> dequeue(){
            if(size == 0)
            {
                return pair<int, string>(-1, "dummy");
            }
            // pega o valor do front
            Node* temp = front->getNext();
            pair<int, string> value = temp->getData();
            
            // define o novo front
            front->setNext(front->getNext()->getNext());
            if(front->getNext() == nullptr)
            {
                rear = front;
            }
            size--;
            delete temp;            // deleta o antigo front
            return value;
        }

        bool isEmpty() const {return size == 0;};
        
        pair<int, string> frontValue() const {
            return front->getNext()->getData();
        };

        int getSize() const {return size;};
    
};

int main(){
    int numCases;
    cin >> numCases;
    cin.ignore();

    while (numCases--)
    {
        Queue* qleft = new Queue();
        Queue* qright = new Queue();
        string currSide = "left";
        int ferryLength, numCars, capacity, count = 0;
        cin >> ferryLength >> numCars;
        cin.ignore();
        
        ferryLength *= 100;

        // recebe todos os carros
        while(numCars--)
        {
            string carSide;
            int carLength;
            cin >> carLength >> carSide;
            cin.ignore();
            if(carSide == "left")
            {
                qleft->enqueue({carLength, carSide});
            }
            else
            {
                qright->enqueue({carLength, carSide});
            }
        }


        // enquanto houver carros em ao menos uma fila
        while(!qleft->isEmpty() || !qright->isEmpty())
        {
            int capacity = ferryLength;

            
            if(currSide == "left")
            {
                while(!qleft->isEmpty() && (qleft->frontValue().first <= capacity) && (qleft->frontValue().second == currSide))
                {
                    capacity -= qleft->frontValue().first;
                    qleft->dequeue();
                }
                count ++;
                currSide = (currSide == "left") ? "right" : "left";
            }
            else
            {
                while(!qright->isEmpty() && qright->frontValue().first <= capacity && qright->frontValue().second == currSide)
                {
                    capacity -= qright->frontValue().first;
                    qright->dequeue();
                }
                count ++;
                currSide = (currSide == "left") ? "right" : "left";
            }
        }

        cout << count << endl;
        delete qleft , qright;
    }


    return 0;
}