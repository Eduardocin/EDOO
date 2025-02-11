#include <iostream>
#include <string>

using namespace std;

class Node{
    friend class LinkedList;
    private:
        int data;
        Node* next;
    
    public:
    Node(){
        this->data = 0;
        this->next = nullptr;
    }    
    
    Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
    
};


class LinkedList{
    private:
        Node* head;
        Node* tail;
        Node* curr;
        int size;
    
    public:
        LinkedList(){
            head = tail = curr = new Node();
            size = 0;
        }

        ~LinkedList(){
            moveToStart();
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }	

        void insert(int data){
            curr->next = new Node(data, curr->next);
            if(tail == curr){
                tail = curr->next;
            }
            size++;
        }
        
        void moveToStart(){
            curr = head;
        }   

        void prev(){
            if(curr == head)
            {
                return;
            }
            Node* temp = head;
            
            while(temp->next != curr)
            {
                temp = temp->next;
            }
            curr = temp;
        }

        void next()
        {
            if(curr != tail)
            {
                curr = curr->next;
            }
        }

        int remove(){
            if(curr->next == nullptr) // No element to remove
            {
                return -1;
            }

            int temp = curr->next->data; // Store the data of the node to be removed
            if(tail == curr->next)
            {
                tail = curr;
            }

            curr->next = curr->next->next;
            size--;
            return temp;
        }

        int count(int data){
            int count = 0;
            Node* temp = head->next;
            while(temp != nullptr){
                if(temp->data == data){
                    count++;
                }
                temp = temp->next;
            }
            return count;
        }


};


int main(){
    int  cases;
    cin >> cases;
    cin.ignore();

    while(cases--){
        int operations;
        cin >> operations;
        cin.ignore();
        
        LinkedList* list = new LinkedList();
        while(operations--){
            string op;
            cin >> op;
            if(op == "insert"){
                int data;
                cin >> data;
                list->insert(data);
            }
            else if(op == "remove"){
                list->remove();
            }
            else if(op == "count"){
                int data;
                cin >> data;
                cout << list->count(data) << endl;
            }
            else if(op == "prev"){
                list->prev();
            }
            else if(op == "next"){
                list->next();
            }
        }
        delete list;
    }

}