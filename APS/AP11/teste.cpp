#include <vector>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;



class HashNode {
    private:
        int key;
        int value;
        bool empty;
    public:
        HashNode(): empty(true) {}
        HashNode(int key, int value): key(key), value(value), empty(false) {}

        int getKey() const {return key;}
        int getValue() const {return value;}
        bool getEmpty() const {return empty; }

        void setEmpty(bool val) {empty = val;}
};

class HashTable{
    private:
        int size;
        int count;
        vector<HashNode> table;
        vector<bool> removed;
        vector<int> perm;

        int hashFunction(const int& key) const {
                int temp = (int) floor((((double) key) / ((double) size))); 
                return (key - (size * temp)); }

        
    
    public:
        HashTable(int size) : size(size), count(0){
            table.resize(size, HashNode());
            removed.resize(size, false);
            perm.resize(size, 0);
        }

        HashNode operator[](int pos) const {
            return table[pos];
        }

        int pseudoRandom(int hashIndex, int i) const {
            int newPos = (hashIndex + perm[i]) % size;
            return newPos;
        }

        int find(const int& key) const {
            int pos = hashFunction(key);

            if(table[pos].getKey() == key && !table[pos].getEmpty())
            {
                return pos;
            }

            if(!table[pos].getEmpty() || removed[pos])
            {
                int i = 0;
                int newPos;
                do{
                    i++;
                    newPos = pseudoRandom(pos, i);
                    if(table[newPos].getKey() == key && !table[newPos].getEmpty())
                    {
                        return newPos;
                    }
                } while(table[newPos].getKey() != key && (!table[newPos].getEmpty() || removed[newPos]) && i < 20);
            }
            
            return -1;
        }



        void insert(const int& key, const int& value) {
            if (count < size && find(key) == -1)
            {
                int pos = hashFunction(key);

                if (!table[pos].getEmpty() && !removed[pos])
                {

                    unsigned int i = 0;
                    int newPos;
                    do
                    {
                        i++;
                        newPos = pseudoRandom(pos, i);
                    }while(!table[newPos].getEmpty() && !removed[newPos] && i < 20);
                    pos = newPos;
                }
                table[pos] = HashNode(key, value);
                removed[pos] = false;
                count++;
                return;
            }
            return;
        }

        void setPermArray(int& value, int pos){
            perm[pos] = value;
        }

};


int main(){
    int size;
    
    while(cin >> size && size != 0) {
        int key, value, numOp;
        string op;
        cin.ignore();

        HashTable ht(size);
        for(int i = 0; i < size-1; i++){
            cin >> value;
            ht.setPermArray(value, i+1); 
        }

        cin >> numOp;
        while(numOp--){
            cin >> op;
            if(op == "add")
            {
                cin >> key >> value;
                ht.insert(key, value);
            }
            else if(op == "find")
            {
                cin >> key;
                int pos = ht.find(key);
                if(pos == -1){
                    cout << pos << endl;
                }
                else{
                    cout << pos << " " << ht[pos].getValue() << endl;
                }
            }
        }
    }
    return 0;
}