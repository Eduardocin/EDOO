#include <iostream>
#include <queue>

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
        

    public:
        BST(): root(nullptr), nodeCount(0){}
        
        ~BST(){
            delete root;
        }

        void insert(const int& data){
            root = insert(root, data);
            return;
        }

        int height() const
        {
            if(root == nullptr){
                return -1;
            }

            queue<Node*> q;
            q.push(root);
            int height = -1;
            while(!q.empty())
            {
                height++;
                int levelSize = q.size();
                for(int i = 0; i < levelSize; i++)
                {
                    Node* current = q.front();
                    q.pop();

                    if(current->getLeft() != nullptr)
                    {
                        q.push(current->getLeft());
                    }
                    if(current->getRight() != nullptr)
                    {
                        q.push(current->getRight());
                    }
                }
            }
            return height;
        }

};


int main(){
    int numNodes, data;
    cin >> numNodes;
    BST* bst = new BST();

    while(numNodes--){
        cin >> data;
        bst->insert(data);
    }

    cout << bst->height();

    return 0;
}


