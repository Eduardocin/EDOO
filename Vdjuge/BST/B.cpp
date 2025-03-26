#include <iostream>
#include <string>
#include <stack>

using namespace std;

class BSTNode{
    private:
        char data;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(char data): data(data), left(nullptr), right(nullptr){}

        ~BSTNode(){
            delete left;
            delete right;
        }

        char getData() const {
            return data;
        }

        void setLeft(BSTNode* left){
            this->left = left;
        }

        void setRight(BSTNode* right){
            this->right = right;
        }

        BSTNode* getLeft() const {
            return left;
        }

        BSTNode* getRight() const {
            return right;
        }
        
};


class BST{
    private:
        BSTNode* root;
        int nodeCount;

        BSTNode* insert(BSTNode* root, const char& data){
            if(root == nullptr){
                return new BSTNode(data);
            }

            if(root->getData() > data){
                root->setLeft(insert(root->getLeft(), data));
            }
            else{
                root->setRight(insert(root->getRight(), data));
            }
            return root;
        }

        void printPreOrder(BSTNode* root){
            if(root == nullptr){
                return;
            }

            cout << root->getData();
            printPreOrder(root->getLeft());
            printPreOrder(root->getRight());
        }

    public:
        BST(): root(nullptr), nodeCount(0){}


        ~BST(){
            delete root;
        }

        void insert(const char& data){
            root = insert(root, data);
            nodeCount++;
        }

        void printPreOrder() {
            printPreOrder(root);
        }

};


int main(){
    stack<char> s;
    string data;
    char c;
    BST* bst = new BST();


    while(getline(cin, data))
    {
        if(data == "*")
        {
            while(!s.empty())
            {
                c = s.top();
                bst->insert(c);
                s.pop();
            }

            bst->printPreOrder();
            cout << endl;
            delete bst;
            bst = new BST();
        }
        else if(data != "$")
        {
            for(char c : data){
                s.push(c);
            }
        }


        if(data == "$")
        {
            while(!s.empty())
            {
                c = s.top();
                bst->insert(c);
                s.pop();
            }
            bst->printPreOrder();
            cout << endl;
            break;
        }
        
    }

    delete bst;
    return 0;
}