#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class HashNode {
    private:
        int key;
        string value;
    public:
        HashNode(int k, string v) : key(k), value(v) {}
        int getKey() const { return key; }

        string getValue() const { return value;}

        bool operator==(const HashNode& other) const {
            return key == other.key; 
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
            table.resize(size, list<HashNode>());
        }

        int find(int key) const {
            int pos = hashFunction(key);
            for(const auto& node : table[pos])
            {
                if(node.getKey() == key)
                {
                    return pos;
                }
            }
            return -1;
        }

        
        void insert(int key, string value){
            if(find(key) != -1) 
            {
                return;
            }

            int pos = hashFunction(key);
            table[pos].emplace_back(key, value);
            count++;;
        }

        void print() {
            for(int i = 0; i < size; i++) 
            {
                cout << i << ":";
                if(!table[i].empty())
                {
                    bool first = true;
                    for(const auto &node : table[i]) 
                    {
                        if(!first) cout << ",";
                        cout << "(" << node.getKey() << "," << node.getValue() << ")";
                        first = false;
                    }
                }
                cout << endl;
            }
        }

        void del(int key){
            int pos = find(key);
            
            if(pos != -1) 
            {
                HashNode tempNode(key, "");
                table[pos].remove(tempNode);  
                count--;              
            }
        }

        string loadFactor() const {
            string loadFactor = to_string(count) + "/" + to_string(size);
            return loadFactor;
        }
};


int main(){
    int DICTSIZE = 10;
    int numCases, numOperations;
    string typeOperation;

    cin >> numCases;

    for(size_t i = 0; i < numCases; i++){  
        HashTable dict(DICTSIZE);  
        cin >> numOperations;
        while(numOperations--){
            cin >> typeOperation;
            if(typeOperation == "add"){
                int key;
                string value;
                cin >> key >> value;
                dict.insert(key, value);
            }
            else if(typeOperation == "del"){
                int key;
                cin >> key;
                dict.del(key);
            }
        }

        cout << "caso " << i + 1  << ":" << endl;
        cout << "alpha = " << dict.loadFactor() << endl;
        dict.print();
    }


    return 0;
};