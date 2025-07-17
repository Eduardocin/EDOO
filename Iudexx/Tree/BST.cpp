#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(const int& data): data(data), left(nullptr), right(nullptr){}

        ~Node(){
            delete left;
            delete right;
        }

        int getData() const {return data;}

        void setData(int data) {
            this->data = data;
        }

        Node* getLeft() const {return left;}
        Node* getRight() const {return right;}

        void setLeft(Node* left){
            this->left = left;
        }

        void setRight(Node* right){
            this->right = right;
        }
};


class BST{
    private:
        Node* root;
        int nodeCount;

        Node* insert(Node* root, const int& data)
        {
            if(root == nullptr)
            {
                return new Node(data);
            }

            if(root->getData()> data)
            {
                root->setLeft(insert(root->getLeft(), data));
            }
            else
            {
                root->setRight(insert(root->getRight(), data));
            }
            return root;
        }

        void posOrder(Node* root){
            if(root != nullptr)
            {
                posOrder(root->getLeft());
                posOrder(root->getRight());
                cout << root->getData() << endl;
            }
        }
        
        Node* getmin(Node* root){
            if(root->getLeft() == nullptr){
                return root;
            }
            return getmin(root->getLeft());
        }

        Node* deleteMin(Node* root){
            if(root->getLeft() == nullptr)
            {
                return root->getRight();
            }
            root->setLeft(deleteMin(root->getLeft()));
            return root;
        }

        Node* remove(Node* root, int data){
            if(root == nullptr)
            {
                return nullptr; 
            }

            if(root->getData() > data)
            {
                root->setLeft(remove(root->getLeft(), data));
            }
            else if(root->getData() < data){
                root->setRight(remove(root->getRight(), data));
            }
            else
            {
                if(root->getLeft() == nullptr)
                {
                    return root->getRight();
                }
                else if(root->getRight() == nullptr)
                {
                    return root->getLeft();
                }
                else
                {
                    Node* temp = getmin(root->getRight());
                    root->setData(temp->getData());
                    root->setRight(deleteMin(root->getRight()));
                }
            }
            return root;
        }

        int find(Node* root, int data){
            if(root == nullptr)
            {
                return -1;
            }
            
            if(root->getData() > data)
            {    
                return find(root->getLeft(), data);
            }
            else if(root->getData() == data)
            {
                return root->getData();
            }
            else{
                return find(root->getRight(), data);
            }
        }

    public:
        BST(): root(nullptr), nodeCount(0){}
        
        ~BST(){
            delete root;
        }

        void insert(const int& data){
            root = insert(root, data);
            nodeCount++;
        }
        
        int find(int data){
            return find(root, data);
        }

        void printPosOrder(){
            posOrder(root);
        }

        int remove(int data){
            int temp = find(root, data);

            if(temp != -1)
            {
                root = remove(root, data);
                nodeCount--;
            }
            return temp;
        }

        int size(){
            return nodeCount;
        }
};


int main(){
    int numCommands, data;
    string command;
    cin >> numCommands;
    BST* bst = new BST();

    while(numCommands--){
        cin >> command;
        if(command == "ins")
        {
            cin >> data;
            bst->insert(data);
        }
        else if(command == "rem")
        {
            cin >> data;
            bst->remove(data);
        }
    }
    
    cout << bst->size() << endl;
    bst->printPosOrder();
    
    delete bst;

    return 0;
}


