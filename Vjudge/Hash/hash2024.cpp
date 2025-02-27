#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
using namespace std;

template<typename K, typename V >
class HashTable{
private:
    struct Entry{
        K key;
        V value;
        int state; // 0: empty, 1:occupied
        Entry():state(0){}
        Entry(K key, V value):key(key), value(value),state(1){}
    };
    
    int size;
    int capacity;
    vector<Entry> table;

    int hash(K key){
        int temp = (int) floor((((double) key) / ((double) capacity))); 
        return (key - (capacity * temp)); 
    }
    
    int pseudo_random(int h, int i){
        return (h + perm[i - 1]) % capacity;
    }

public:
    vector<int> perm;
    
    HashTable(int capacity):size(0), capacity(capacity){
        table.assign(capacity, Entry());
        perm.resize(capacity-1);
    }

    int findV(const int& index){
        return table[index].value;
        }

    int findIndex(const K& key){
        int h = hash(key);
        int pos = h;
        if(table[pos].state == 1 && table[pos].key == key){
            return  pos;
        }
        else{
            for(int i = 1; i < capacity; i++){
                int pos = pseudo_random(h, i);
                if(table[pos].state == 1 && table[pos].key == key){
                    return  pos;
                }
                else if(table[pos].state == 0){
                    return  -1;
                }
            }
        }
        return  -1;
    }

    void insert(const K& key, const V& value){
        
        if(size < capacity){
            int  result = findIndex(key);
            if(result != -1){
                return;
            }

            int h = hash(key);
            int pos = h;
            if(table[pos].state == 0){
                table[pos] = Entry(key, value);
                size++;
                return;
            }else{
                for(int i = 1; i < capacity; i++){
                    int pos = pseudo_random(h, i);
                    if(table[pos].state == 0 ){
                        table[pos] = Entry(key, value);
                        size++;
                        return;
                    }
                }
            }
                
        }
        
    }

};

int main(){
    int tam_arr_perm, value_perm, num_operations, key, value;
    string command;
    
    while(cin >> tam_arr_perm && tam_arr_perm!= 0){
            
        HashTable<int, int> table(tam_arr_perm);

        for(int i = 0; i < tam_arr_perm-1; i++){
            cin >> value_perm;
            table.perm[i] = value_perm;
        }
        

        cin >> num_operations;
        for(int i = 0; i < num_operations; i++){
            cin >> command;
            if(command == "add"){
                cin >> key >> value;
                table.insert(key, value);
            }
            if(command == "find"){
                cin >> key;
                int pos = table.findIndex(key);
                if(pos != -1){
                    int value = table.findV(pos);
                    cout << pos << " " <<  value << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}
