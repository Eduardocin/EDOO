#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string data;
    Node* next;
public:
    Node(string data = "Dummy", Node* next = nullptr) : data(data), next(next) {}

    string getData() const {
        return data;
    }

    Node* getNext() const {
        return next;
    }


    void setNext(Node* next) {
        this->next = next;
    }

};


class LinkedList {
private:
    Node* head;
    Node* tail;
    Node* curr;
    int count;

public:
    LinkedList() {
        head = tail = curr = new Node();
        count = 0;
    }

    //Destructor


    void insert(string pessoa) {
        // Insere sempre no final, usando tail
        tail->setNext(new Node(pessoa, nullptr));
        tail = tail->getNext();
        count++;
    }

    void insertPos(string pessoa, int pos) {
        int countpos = 1;
        Node* temp = head;
        while (countpos < pos && temp->getNext() != nullptr) {
            temp = temp->getNext();
            countpos++;
        }
        Node* newNode = new Node(pessoa, temp->getNext());
        temp->setNext(newNode);
        if(newNode->getNext() == nullptr) {
            tail = newNode;
        }
        count++;
    }


    void next() {
        if(curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
    }


    string remove() {
        if (curr->getNext() == nullptr) {
            return "invalid";
        }
        Node* temp = curr->getNext();
        string name = curr->getNext()->getData();

        if (tail == curr->getNext()) {
            tail = curr;
        }

        curr->setNext(curr->getNext()->getNext());
        
        
        count--;
        delete temp;
        return name;
    }


    bool isEmpty() {
        return count == 0;
    }

    void moveToStart() {
        curr = head;
    }


    void status() {
        Node* temp = head->getNext();
        if (temp == nullptr) { 
            cout << "---" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->getData();
            temp = temp->getNext();
            if (temp != nullptr)
                cout << ", ";
            else
                cout << endl;
        }
    }
    
};



int main() {
    string name, op;
    int numCases, countCases = 1;

    cin >> numCases;
    cin.ignore();

    while (numCases--) {
        LinkedList* list = new LinkedList();
        int numOp;
        cin >> numOp;
        cout << "caso "<< countCases << ":" << endl;
        while (numOp--)
        {
            cin >> op;
            if (op == "add")
            {
                cin >> name;
                int pos = -1;
                try {
                    pos = stoi(name);
                    cin >> name;
                    list->insertPos(name, pos);
                }
                catch (const std::invalid_argument& e) {
                    list->insert(name);
                }
            }
            else if (op == "status")
            {
                if (list->isEmpty()) {
                    cout << "---" << endl;
                }
                else {
                    list->status();
                }
            }
            else if (op == "next") {
                if (list->isEmpty()) {
                    continue;
                }
                else {
                    list->remove();
                }
            }
        }
        countCases++;
    }


    return 0;
}