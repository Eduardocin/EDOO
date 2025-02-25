#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class HashNode {
    private:
        int key;
        int value;
    public:
        HashNode(int k, int v) : key(k), value(v) {}
        int getKey() const { return key; }
        int getValue() const { return value;}


        bool operator==(const HashNode& other) const {
            return key == other.key;  // Comparação apenas pela chave
        }
};

class HashTable{
    private:
        int size;
        int count;
        vector<list<HashNode>> table;

        int hashFunction(int key) const {
            return key % 10;
        }

    public:
        HashTable(int size) : size(size), count(0){
            table.assign(size, list<HashNode>()); //Replaces the contents with count copies of value value.
        }

        int hash(int key) const {
            return hashFunction(key);
        }

        
        void insert(int key, int value){
            int pos = hash(key);


            HashNode tempNode(key, 0); 
            auto it = find(table[pos].begin(), table[pos].end(), tempNode);
                if(it != table[pos].end())
                {
                    return;
                }
    
            table[pos].push_back(HashNode(key, value));
            count++;
        }

        void print(){

            for(int i = 0; i < count; i++){
                //Check if the list is empty
                if(table[i].empty()){
                    continue;
                }
                else{
                    cout << i << " ";
                    for(const auto &node : table[i]){
                        cout << node.getKey() << " ";
                    }
                }
                cout << endl;
            }
        }
};


int main(){
    int numCases;
    cin >> numCases;
    cin.ignore();

    HashTable table(numCases);
    while(numCases--){
        int val;
        cin >> val;
        table.insert(val, val);
    }

    table.print();

    return 0;
};