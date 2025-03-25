#include <iostream>
#include <string>

using namespace std;

class BSTNode{
    private:
        int data;
        BSTNode* left;
        BSTNode* right;
    
    public:
        BSTNode(int data): data(data), left(nullptr), right(nullptr){}

        ~BSTNode(){
            delete left;
            delete right;
        }	

        int getData() const {
            return data;
        }

        BSTNode* getLeftChild() const {
            return left;
        }

        BSTNode* getRightChild() const {
            return right;
        }

        void setLeftChild(BSTNode* left){
            this->left = left;
        }

        void setRightChild(BSTNode* right){
            this->right = right;
        }

};

class BST{
    private:
        BSTNode* root;
        int nodeCount;

        BSTNode* insert(BSTNode* root, const int& data){
            if (root == nullptr){
                return new BSTNode(data);
            }

            if (root->getData() > data) 
            {
                root->setLeftChild(insert(root->getLeftChild(), data));
            }
            else
            {
                root->setRightChild(insert(root->getRightChild(), data));
            }
            return root;
        }
        
        void traverseInOrder(BSTNode* root) const {
            if(root == nullptr){
                return;
            }

            traverseInOrder(root->getLeftChild());
            cout << " " << root->getData();
            traverseInOrder(root->getRightChild());
        }


        void traversePostOrder(BSTNode* root) const {
            if(root == nullptr){
                return;
            }

            traversePostOrder(root->getLeftChild());
            traversePostOrder(root->getRightChild());
            cout << " " << root->getData();
        }


        void traversePreOrder(BSTNode* root) const {
            if(root == nullptr){
                return;
            }

            cout << " " << root->getData();
            traversePreOrder(root->getLeftChild());
            traversePreOrder(root->getRightChild());
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

        void printInOrder() const {
            cout << "In order  :";
            traverseInOrder(root);
            cout << endl;
        }

        void printPostOrder() const {
            cout << "Post order:";
            traversePostOrder(root);
            cout << endl;
        }

        void printPreOrder() const {
            cout << "Pre order :";
            traversePreOrder(root);
            cout << endl;
        }
};

int main(){
    int countNodes, data;
    BST* bst = new BST();
    cin >> countNodes;
    cin.ignore();
    
    while(countNodes--){
        int data;
        cin >> data;
        bst->insert(data);
    }

    bst->printPreOrder();
    bst->printInOrder();
    bst->printPostOrder();

    delete bst;

};