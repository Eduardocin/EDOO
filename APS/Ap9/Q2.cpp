#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        int data;
        Node* next;
    
    public:
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

        // Getters
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


class LinkedList {
    private:
        Node* head;
        Node* tail;
        Node* curr;
        int size;
    
    public:
        LinkedList() {
            head = tail = curr = new Node();
            size = 0;
        }

        ~LinkedList() {
            moveToStart();
            while(head != nullptr) {
                Node* temp = head;
                head = head->getNext();
                delete temp;
            }
        }

        void insert(int data) {
            curr->setNext(new Node(data, curr->getNext()));
            if(tail == curr) {
                tail = curr->getNext();
            }

            size++;
        }
        
        void moveToStart() {
            curr = head;
        }   

        void prev() {
            if(curr == head) {
                return;
            }
            Node* temp = head;
            
            while(temp->getNext() != curr) {
                temp = temp->getNext();
            }
            curr = temp;
        }

        void next() {
            if(curr != tail) {
                curr = curr->getNext();
            }
        }

        int remove() {
            if(curr->getNext() == nullptr) // No element to remove
            {
                return -1;
            }
            
            Node* temp = curr->getNext();
            int data = temp->getData();

            curr->setNext(temp->getNext());

            if(temp == tail) {
                tail = curr;
            }

            size--;
            delete temp;
            return data;
        }

        int count(int data) {
            int count = 0;
            Node* temp = head->getNext();
            while(temp != nullptr) {
                if(temp->getData() == data) {
                    count++;
                }
                temp = temp->getNext();
            }
            return count;
        }
};


int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    while(cases--) {
        int operations;
        cin >> operations;
        cin.ignore();
        
        LinkedList* list = new LinkedList();
        while(operations--) {
            string op;
            cin >> op;
            if(op == "insert") {
                int data;
                cin >> data;
                list->insert(data);
            }
            else if(op == "remove") {
                list->remove();
            }
            else if(op == "count") {
                int data;
                cin >> data;
                cout << list->count(data) << endl;
            }
            else if(op == "prev") {
                list->prev();
            }
            else if(op == "next") {
                list->next();
            }
        }
        delete list;
    }
}