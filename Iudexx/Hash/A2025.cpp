#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


class HashNode{
    private:
        int key;
        int value;
        bool empty;
    public:
        HashNode(): empty(true) {}
        HashNode(int key, int value): key(key), value(value), empty(false) {}

        // Getters
        int getKey() const  { return key; }
        int getValue() const { return value; }
        bool isEmpty() const { return empty; }

        // Setters
        void setEmpty(bool empty) { this->empty = empty; }
};


class HashTable{
    private:
        vector<HashNode> table;
        vector<bool> removed;
        vector<int> perm;
        int size;
        int count;


        int hashFunct(int key, int mod) const {
            int temp = (int) floor((((double) key) / ((double) mod)));
            return (key - (mod * temp)); 
        }

    public:
        HashTable(int size): size(size), count(0){
            table.assign(size, HashNode());
            removed.assign(size, false);
            perm.assign(size, 0);
        }
        
        HashNode operator[](int pos) const {
            return table[pos];
        }

        int pseudoRandom(int key, int i) const {
            return (hashFunct(key, size) + perm[i]) % size;
        }


        int find(int key) const {
            int p = hashFunct(key, size);
            
            if (table[p].getKey() == key && !table[p].isEmpty()){
                return p;
            }
        
            if(!table[p].isEmpty() || removed[p]){ 
                for(int i = 1; i < size; i++){  
                    int newPos = pseudoRandom(p, i);
                    
                    if(table[newPos].getKey() == key && !table[newPos].isEmpty()){
                        return newPos;
                    }
                    
                    if(table[newPos].isEmpty() && !removed[newPos]){
                        return -1;
                    }
                }
            }
            return -1;
        }


        void insert(int key, int value) {
            if (count < size){
                int searchPos = find(key);
                if (searchPos == -1){
                    int pos = hashFunct(key, size);
                    if (!table[pos].isEmpty() && !removed[pos]){
                        int i = 0;
                        int newPos;
                        do{
                            i++;
                            newPos = pseudoRandom(pos, i);
                        } while (!table[newPos].isEmpty() && !removed[newPos]);
                        pos = newPos;
                    }
                    table[pos] = HashNode(key, value);
                    removed[pos] = false;
                    count++;
                    return;
                }
            }
            return;
        }


        void remove(int key) {
            int pos = find(key);
            if (pos != -1){
                table[pos] = HashNode();
                removed[pos] = true;
                count--;
            }
            return;
        }

        void setPerm(int &value, int pos){
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
            ht.setPerm(value, i+1); 
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