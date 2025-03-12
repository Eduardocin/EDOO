#include <vector>
#include <string>
#include <iostream>

using namespace std;

class HashNode {
    private:
        string key;
        bool empty;
    public:
        HashNode(): empty(true) {}
        HashNode(string key): key(key), empty(false) {}

        string getKey() const {return key;}
        bool getEmpty() const {return empty; }

        void setEmpty(bool val) {empty = val;}

};

class HashTable{
    private:
        int size;
        int count;
        vector<HashNode> table;
        vector<bool> removed;

        int hashFunction(string key) const {
            int sum = 0;
            for(int i = 0; i < key.length(); i++)
            {
                sum += int(key[i])* (i+1);
            }

            return (19*sum) % 101;
        }
    
    
    public:
        HashTable(int size){
            this->size = size;
            count = 0;
            table.assign(size, HashNode());
            removed.assign(size, false);
        }

        int getSize() const {return count;}

        int quadratic_prob(int hashIndex, int probIndex) const {
            int newPos = (hashIndex + (probIndex*probIndex) + 23*probIndex) % 101;
            return newPos;
        }

        int find(string key) const {
            int pos = hashFunction(key);

            if(table[pos].getKey() == key && !table[pos].getEmpty())
            {
                return pos;
            }
            else
            {
                for(int i = 1; i < 20; i++)
                {
                    int newPos = quadratic_prob(pos,i);

                    if(table[newPos].getKey() == key && !table[newPos].getEmpty())
                    {
                        return newPos;
                    }

                    if(table[newPos].getEmpty() && !removed[newPos])
                    {
                        return -1;
                    }
                }
            }
            return -1;
        }

        void insert(string key){
            if(count < size && find(key) == -1)
            {
                int pos = hashFunction(key);
                if(!table[pos].getEmpty() && !removed[pos])
                {
                    for(int i = 1; i < 20; i++){
                        int newPos = quadratic_prob(pos, i);
                        if(table[newPos].getEmpty() || removed[newPos]){
                            pos = newPos;
                            break;
                        }
                    }
                }
                
                if (table[pos].getEmpty() || removed[pos])
                {
                    table[pos] = HashNode(key);
                    removed[pos] = false;
                    count++;
                }
            }
        }

        void remove(string key) {
            int pos = find(key);
            if(pos != -1){
                table[pos].setEmpty(true);
                removed[pos] = true;
                count--;
            }
            return;
        }

        void print(){
            for(int i = 0; i < size; i++){
                if(!table[i].getEmpty())
                {
                    cout << i << ":" << table[i].getKey() << endl;
                }
            }
        }
};

int main(){
    int numCases, numOp;
    cin >> numCases;
    while(numCases--)
    {
        string op, key;
        HashTable* table = new HashTable(101);
        cin >> numOp;
        cin.ignore();
        
        while(numOp--)
        {   
            getline(cin, op, ':');
            getline(cin, key);
            
            if(op == "ADD")
            {
                table->insert(key);
            }
            else
            {
                table->remove(key);
            }

        }
        cout << table->getSize() << endl;
        table->print();
        delete table;
    }

    return 0;
}