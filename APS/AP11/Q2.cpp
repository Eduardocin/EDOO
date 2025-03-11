#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashNode{
    private:
        string value;
        string key;
        bool empty;
    public:
        HashNode():empty(true) {};
        HashNode(string key ,string value):key(key) , value(value), empty(false) {}
        
        // Getters 
        string getKey() const { return key; }
        string getValue() const { return value; }
        bool getEmpty() const { return empty; }

        // Setters
        void setEmpty(bool empty) { this->empty = empty; }
};

class HashTable{
    private:
        int size;
        int count;
        vector<HashNode> table;
        vector<bool> removed;

        int hashFunction(string key) const{
            int sum = 0;
            int s = key.size();
            for(int i = 0; i < s; i++)
            {
                sum += key[i];
            }
            return sum % size;
        }

    public:
        HashTable(int size):size(size), count(0){
            //assign(size_type count, const T& value)
            table.assign(size, HashNode());
            removed.assign(size, false);
        }
        
        int linear_prob(int h, int i) const {
            int newPos = (h + i) % size;
            return newPos;
        }

        bool isEmpty(int pos) const {
            return table[pos].getEmpty();
        }


        void insert(string key, string value){
            /*      
            1. First, check if the table has enough space and the key doesn't already exist
            2. Calculate the initial position using the hash function
            3. If the position is occupied (not NULL and not a deleted marker):
            4. Use linear prob to find a new position
            5. Keep trying different offsets from linear prob until finding an empty or deleted slot
            6. Insert the entry at the found position
            7. Increment the counter
            */
            if (count < size) {
                int searchPos = find(key);
                if (searchPos == -1) {  
                    int pos = hashFunction(key);
                    
                    if (!table[pos].getEmpty() && !removed[pos]) {
                        int i = 0;
                        int newPos;
                        do {
                            i++;
                            newPos = linear_prob(pos, i); 
                        } while (!table[newPos].getEmpty() && !removed[newPos]);
                        
                        pos = newPos;
                    }
                    
                    table[pos] = HashNode(key, value);
                    removed[pos] = false;  
                    count++;
                }
            }
        }

        void remove(string key){
            int pos = find(key);
            if(pos != -1){
                table[pos] = HashNode();
                removed[pos] = true;
                count--;
            }
        }



        int find(string key) const {
        /*
        1. Calculate the initial position using the hash function
        2. If the initial position is the key we're looking for, return it
        3. If the initial position is occupied and not the key we're looking for, use the probing sequence
        4. If we find the key, return it
        5. If we find an empty slot, the key doesn't exist
        6. If we find a deleted slot, keep looking
        7. If we reach the end of the probing sequence, the key doesn't exist
        8. Return -1
        */
            int pos = hashFunction(key);
            
            // Check initial position
            if(table[pos].getKey() == key && !table[pos].getEmpty()){
                return pos;
            }
            
            // If occupied and not the key we're looking for, use probing sequence
            if(!table[pos].getEmpty() || removed[pos]){
                for(int i = 1; i < size; i++) {
                    int newPos = linear_prob(hashFunction(key), i);
                    
                    if(table[newPos].getKey() == key && !table[newPos].getEmpty()){
                        return newPos;
                    }
                    
                    if(table[newPos].getEmpty() && !removed[newPos]){
                        break;
                    }
                }
            }
            return -1;
        }


};


int main(){
    int numOp;
    string command, key;

    cin >> numOp;
    
    HashTable table(numOp);

    for(int i = 0; i < numOp; i++){
        cin >> command;
        
        if(command == "fim"){
            break;
        }
        else if(command == "add"){
            cin >> key;
            table.insert(key, key);
        }
        else if(command == "sch"){
            cin >> key;
            int pos = table.find(key);
            cout << key << " " << pos << endl;
        }
        else if(command == "rmv"){
            cin >> key;
            table.remove(key);
        }
    }


    return 0;

}