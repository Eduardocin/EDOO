#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


enum class CellState {
    EMPTY,
    OCCUPIED,
    REMOVED
};

class HashNode{
    private:
        int key;
        int value;
        CellState state;
    public:
        HashNode(): state(CellState::EMPTY) {}
        HashNode(int k, int v) : key(k), value(v), state(CellState::OCCUPIED) {}

        int getKey() const  { return key; }
        int getValue() const { return value; }
        CellState getState() const {return state;}

        void setState(CellState state) { this->state = state; }


        bool isEmpty() const {
            return state == CellState::EMPTY;
        }

        bool isRemoved() const {
            return state == CellState::REMOVED;
        }

        bool isOccupied() const {
            return state == CellState::OCCUPIED;
        }
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
            /*
            * 1. Calculate the initial position using the hash function
            * 2. Check if the key is at the initial position
            * 3. If not, and the position is not empty or was removed:
            *    a. Use the probing sequence to check alternative positions
            *    b. If the key is found, return its position
            *    c. Continue until finding an empty position or reaching the attempt limit
            * 4. If not found, return -1
            */
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
            /*
            * Inserts a key-value pair into the hash table
            * 1. Check if there is available space in the table
            * 2. Check if the key already exists
            * 3. If it doesn't exist:
            *    a. Calculate the position using the hash function
            *    b. If the position is occupied, use probing to find a free position
            *    c. Insert the element in the position found
            *    d. Increment the element counter
            */
            if (elementCount < tableSize)
            {
            size_t searchPos = find(key);
            
            if (searchPos == -1)
            {
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
                table[pos].setState(CellState::REMOVED);
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
