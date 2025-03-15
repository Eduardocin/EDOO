#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;

public:
    explicit Node(const T& data): data(data), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
    }

    T getData() const {
        return data;
    }
    
    Node<T>* getLeftChild() const {
        return left;
    }
    
    Node<T>* getRightChild() const {
        return right;
    }
    
    void setLeftChild(Node<T>* left) {
        this->left = left;
    }
    
    void setRightChild(Node<T>* right) {
        this->right = right;
    }
};

template<typename T>
class BST {
private:
    Node<T>* root;
    int size;

    Node<T>* insertHelp(Node<T>* root, const T& data) {
        if(root == nullptr) {
            return new Node<T>(data);
        }

        if(data < root->getData()) {
            root->setLeftChild(insertHelp(root->getLeftChild(), data));
        } else {
            root->setRightChild(insertHelp(root->getRightChild(), data));
        }

        return root;
    }

    void traverseInOrder(Node<T>* root) const {
        if(root == nullptr) {
            return;
        }

        traverseInOrder(root->getLeftChild());
        cout << root->getData() << " ";
        traverseInOrder(root->getRightChild());
    }

    void traversePostOrder(Node<T>* root) const {
        if(root == nullptr) {
            return;
        }

        traversePostOrder(root->getLeftChild());
        traversePostOrder(root->getRightChild());
        cout << root->getData() << " ";
    }

    void traversePreOrder(Node<T>* root) const {
        if(root == nullptr) {
            return;
        }

        cout << root->getData() << " ";
        traversePreOrder(root->getLeftChild());
        traversePreOrder(root->getRightChild());
    }

public:
    BST(): root(nullptr), size(0) {}

    ~BST() {
        delete root;
    }

    void insert(const T& data) {
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
    
    int getSize() const {
        return size;
    }
    
    bool isEmpty() const {
        return root == nullptr;
    }
};

int main() {
    BST<string> stringTree;
    stringTree.insert("banana");
    stringTree.insert("abacaxi");
    stringTree.insert("laranja");
    stringTree.printInOrder(); 

    BST<float> floatTree;
    floatTree.insert(3.14);
    floatTree.insert(2.71);
    floatTree.insert(1.618);
    floatTree.printInOrder(); 
    return 0;
}