#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
Estados para verificar

Removed (R): Indica que um elemento foi removido da tabela.
Empty (E): Indica que uma posição da tabela está vazia.
(Obs: Um elemento pode ser inserido em uma posição que estava vazia ou que estava marcada como removida.)
(Obs: A busca por um elemento deve parar quando encontrar uma posição (vazia e nao removida) ou uma posição com o elemento buscado.)

*/

class HashNode {
    private:
        string key;
        string value;
        bool empty;
    public:
        HashNode(): empty(true) {}
        HashNode(string key, string value): key(key), value(value), empty(false) {}

        string getKey() const {return key;}
        string getValue() const {return value;}
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
            int s = key.size();
            for(int i = 0; i < s; i++)
            {
                sum += key[i];
            }
            return sum % size;
        }
    
    public:
        HashTable(int size){
            this->size = size;
            count = 0;
            table.assign(size, HashNode());
            removed.assign(size, false);
        }

        int linear_prob(int hashIndex, int probIndex) const {
            int newPos = (hashIndex + probIndex) % size;
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
                for(int i = 1; i < size; i++)
                {
                    int newPos = linear_prob(pos,i);

                    if(table[newPos].getKey() == key && !table[newPos].getEmpty())
                    {
                        return newPos;
                    }
                    else if(table[newPos].getEmpty() && !removed[newPos])
                    {
                        return -1;
                    }
                }
            }
            return -1;
        }



        void insert(string key, string value){
            //check if the table has enough space and the key doesn't already exist
            if(count < size && find(key) == -1)
            {
                int pos = hashFunction(key);
                if(!table[pos].getEmpty() && !removed[pos])
                {
                    for(int i = 1; i < size; i++){
                        int newPos = linear_prob(pos, i);
                        if(table[newPos].getEmpty() || removed[newPos]){
                            pos = newPos;
                            break;
                        }
                    }
                }
                table[pos] = HashNode(key, value);
                removed[pos] = false;
                count++;
            }
        }

        void remove(string key) {
            int pos = find(key);
            if(pos != -1){
                table[pos].setEmpty(true);
                removed[pos] = true;
                count--;
            }
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