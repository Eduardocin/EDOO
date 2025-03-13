#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


class HashNode{
    public:
        enum State {EMPTY, OCCUPIED, REMOVED};
    private:
        int key;
        int value;
        State state;
    public:
        HashNode(): state(EMPTY) {}
        HashNode(int k, int v) : key(k), value(v), state(OCCUPIED) {}

        int getKey() const  { return key; }
        int getValue() const { return value; }
        
        bool isEmpty() const {
            return state == EMPTY;
        }

        bool isRemoved() const {
            return state == REMOVED;
        }

        bool isOccupied() const {
            return state == OCCUPIED;
        }

        void markAsRemoved() {state=REMOVED;}
};

class HashTable{
    private:
        static const size_t MAX_PROBE_ATTEMPTS = 20;

        size_t tableSize;
        size_t elementCount;
        vector<HashNode> table;
        vector<int> probSequence;

        size_t hashFunction(int key) const {
            int temp = (int) floor((((double) key) / ((double) tableSize)));
            return  static_cast<size_t>(key - (tableSize * temp)); 
        }

        size_t getProbePosition(size_t initialPos, size_t i)const 
        {
            return (initialPos + probSequence[i]) % tableSize;
        }	

    public:
        HashTable(size_t size): tableSize(size), elementCount(0){
            table.resize(size);
            probSequence.resize(size, 0);
        }
        
        const HashNode operator[](size_t pos) const {
            return table[pos];
        }

        int find(int key) const {
            size_t pos = hashFunction(key);
            
            if (table[pos].getKey() == key && table[pos].isOccupied()){
                return static_cast<int>(pos);
            }
        
            if(!table[pos].isEmpty() || table[pos].isRemoved()){ 
                size_t probeIndex = 0;
                size_t newPos;
                do{
                    probeIndex++;
                    newPos = getProbePosition(pos, probeIndex);
                    if(table[newPos].getKey() == key && table[newPos].isOccupied()){
                        return static_cast<int>(newPos);
                    }
                } while(table[newPos].getKey() != key && (!table[newPos].isEmpty() || table[newPos].isRemoved()) && probeIndex < MAX_PROBE_ATTEMPTS);
            }
            return -1;
        }


        void insert(int key, int value) {
            if (elementCount < tableSize){

                size_t searchPos = find(key);
                if (searchPos == -1){
                    int pos = hashFunction(key);

                    if (!table[pos].isEmpty() && !table[pos].isRemoved()){
                        size_t probIndex = 0;
                        size_t newPos;
                        do{
                            probIndex++;
                            newPos = getProbePosition(pos, probIndex);
                        } while (!table[newPos].isEmpty() && !table[newPos].isRemoved() && probIndex < MAX_PROBE_ATTEMPTS);
                        pos = newPos;
                    }
                    
                    table[pos] = HashNode(key, value);
                    elementCount++;
                    return;
                }
            }
            return;
        }


        void remove(int key) {
            int pos = find(key);
            if (pos != -1) {
                table[pos].markAsRemoved();
                elementCount--;
                return;
            }
            return;
        }

        void setProbeValue(size_t position, int value) {
            if (position < tableSize) {
                probSequence[position] = value;
            }
        }

};


int main() {
    int size;
    
    while (cin >> size && size != 0) {
        int key, value, numOp;
        string op;
        cin.ignore();

        HashTable ht(size);
        
        for (int i = 0; i < size-1; i++) {
            cin >> value;
            ht.setProbeValue(i+1, value);
        }

        cin >> numOp;
        while (numOp--) {
            cin >> op;
            
            if (op == "add") {
                cin >> key >> value;
                ht.insert(key, value);
            }
            else if (op == "find") {
                cin >> key;
                int pos = ht.find(key);
                
                if (pos == -1) {
                    cout << pos << endl;
                } else {
                    cout << pos << " " << ht[pos].getValue() << endl;
                }
            }
        }
    }
    return 0;
}