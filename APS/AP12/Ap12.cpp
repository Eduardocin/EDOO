#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        int data;
        Node* left;
        Node* right;

    public:
        explicit Node(int data): data(data), left(nullptr), right(nullptr){}

        ~Node(){
            delete left;
            delete right;
        }

        int getData() const {
            return data;
        }
    
        Node* getLeftChild() const {
            return left;
        }
    
        Node* getRightChild() const {
            return right;
        }
    
        void setLeftChild(Node* left) {
            this->left = left;
        }
    
        void setRightChild(Node* right) {
            this->right = right;
        }
};

class BST{
    private:
        Node* root;
        int size;

        /**
         * Algorithm:
         * 1. If the current node is null, creates a new node with the given data (base case)
         * 2. If the data is less than the current node's data, recursively inserts into the left subtree
         * 3. If the data is greater than or equal to the current node's data, recursively inserts into the right subtree
         * 4. Returns the current node to maintain the tree structure
         * 
         * Characteristics:
         * - Maintains the BST property where left child < parent <= right child
         * - Handles duplicates by placing them in the right subtree
         * - Creates new nodes at leaf positions
         */
        Node* insertHelp(Node* root, const int& data){
            if(root == nullptr)
            {
                return new Node(data);
            }

            if(data < root->getData())
            {
                root->setLeftChild(insertHelp(root->getLeftChild(), data));
            }else
            {
                root->setRightChild(insertHelp(root->getRightChild(), data));
            }

            return root;
        }

        /**
        * Algorithm:
        * 1. Checks if the current node is null; if so, returns (base case)
        * 2. Recursively visits the left subtree
        * 3. Visits (prints) the current node
        * 4. Recursively visits the right subtree
        * 
        * Characteristics:
        * - Visits nodes in ascending order in a BST
        * - Useful for getting elements in sorted order
        * 
        */
        void traverseInOrder(Node* root) const {
            if(root == nullptr)
            {
                return;
            }

            traverseInOrder(root->getLeftChild());
            cout << root->getData() << " ";
            traverseInOrder(root->getRightChild());
        }

        /**
        * Algorithm:
        * 1. Checks if the current node is null; if so, returns (base case)
        * 2. Recursively visits the left subtree
        * 3. Recursively visits the right subtree
        * 4. Visits (prints) the current node
        * 
        * Characteristics:
        * - Visits children before the parent node
        * - Useful for cleanup or deletion operations (parent nodes are 
        *   processed after their children)
        * - In post-order traversal, the root is always the last node visited
        * 
        */
        void traversePostOrder(Node* root) const {
            if(root == nullptr)
            {
                return;
            }

            traversePostOrder(root->getLeftChild());
            traversePostOrder(root->getRightChild());
            cout << root->getData() << " ";
        }

        /**
        * Algorithm:
        * 1. Checks if the current node is null; if so, returns (base case)
        * 2. Visits (prints) the current node
        * 3. Recursively visits the left subtree
        * 4. Recursively visits the right subtree
        * 
        * Characteristics:
        * - Visits the parent node before its children
        * - Useful for creating a copy of the tree or for serialization
        * - In pre-order traversal, the root is always the first node visited
        * 
        */
        void traversePreOrder(Node* root) const {
            if(root == nullptr)
            {
                return;
            }

            cout << root->getData() << " ";
            traversePreOrder(root->getLeftChild());
            traversePreOrder(root->getRightChild());
        }

    public:
        BST(): root(nullptr), size(0){}

        ~BST(){
            delete root;
        }

        void insert(const int& data){
            root = insertHelp(root, data);
            size++;
        }

        void printInOrder() const {
            traverseInOrder(root);
        }
    
        void printPostOrder() const {
            traversePostOrder(root);
        }
    
        void printPreOrder() const {
            traversePreOrder(root);
        }
};


int main() {
    string action;
    int numOperations, value;
    BST* bst = new BST();

    cin >> numOperations;
    cin.ignore();
    for(int i = 0; i < numOperations; i++)
    {
        cin >> action;
        if(action == "insert")
        {
            cin >> value;
            bst->insert(value);
        }
        else if(action == "pre")
        {
            bst->printPreOrder();
            cout << endl;
        }
        else if(action == "in")
        {
            bst->printInOrder();
            cout << endl;
        }
        else if(action == "post")
        {
            bst->printPostOrder();
            cout << endl;
        }

    }

    delete bst;

    return 0;
}