#include <string>
#include <vector>
#include <iostream>
using namespace std;

//closed hash
template<typename K, typename V>
class HashTable{
private:
    struct Entry{
        K key;
        V value;
        int state; //0: empty, 1: occupied, 2: deleted

        Entry():state(0){}
        Entry(K key, V value):key(key), value(value), state(1){}
    };
    
    int size;
    int capacity;
    vector<Entry> table;

    
    int hash(K key){
        int hashValue = 0;
        for(int i = 0; i < key.length(); i++){
            hashValue += int(key[i])* (i+1);
        }
        return (19*hashValue) % 101;
    }

    int prob(int h, int i){
        return (h + (i*i) + 23*i) % 101;
    }

public:
    HashTable(int capacity):size(0) ,capacity(capacity){
        table.assign(capacity, Entry());
    }

    V find(const K& key){
        int h = hash(key);
        int pos = h;
        if(table[h].state == 1 && table[h].key == key){
            return table[h].value;
        }else{
            for(int i = 1; i < 20; i++){
                pos = prob(h, i);
                if(table[pos].state == 1 && table[pos].key == key){
                    return table[pos].value;
                }
                else if(table[pos].state == 0){
                    return -1;
                }
            }
        }
        return -1; //if key is not found or a empty position is found
    }

    void insert(const K& key){
        if(size < capacity){
            if(find(key) != -1){
                return;
            }
            else{
                int h = hash(key);
                int pos = h;
                if(table[pos].state == 0 || table[pos].state == 2){
                    V value = pos;
                    table[pos] = Entry(key,value);
                    table[pos].state = 1;
                    size++;
                    return;
                    }
                else{
                    for(int i=1; i < 20; i++){
                        pos = prob(h, i);
                        if(table[pos].state == 0 || table[pos].state == 2){
                            V value = pos;
                            table[pos] = Entry(key, value);
                            table[pos].state = 1;
                            size++;
                            return;
                        }
                    }
                }
            }
        }
    }
    void remove(const K& key){
        if(find(key) == -1){
            return;
        }
        else{
            int h  = hash(key);
            int pos = h;
            if(table[pos].key == key){
                table[pos].state = 2;
                size--;
                return;
            }else{
                for(int i = 1; i < 20; i++){
                    pos = prob(h, i);
                    if(table[pos].key == key){
                        table[pos].state = 2;
                        size--;
                        return;
                    }
                }
            }
        }
    }
    int getSize(){
        return size;
    }

    void print(){
        for(int i = 0; i < capacity; i++){
            if(table[i].state == 1){
                cout << table[i].value << ":" << table[i].key << endl;
            }
        }
    }

    void clear(){
        size = 0;
        table.assign(capacity, Entry());
    }
};


int main(){
    int cases, numOperations;
    string operation, key;
    HashTable<string, int> table(101);
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> numOperations;
        cin.ignore();
        for(int j = 0; j < numOperations; j++){
            getline(cin, operation, ':');
            getline(cin, key);
            if(operation == "ADD" && key.length() > 0){
                table.insert(key);
            }
            else if(operation == "DEL" && key.length() > 0){
                table.remove(key);
            }
        }
        cout << table.getSize() << endl;
        table.print();
        table.clear();
    }
    return 0;
}