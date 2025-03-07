#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class HashNode {
    private:
        string key;
        string value;
        bool isEmpty;
    public:
        HashNode() : isEmpty(true) {}
        HashNode(string k, string v) : key(k), value(v) {}
        string getKey() const { return key; }
        string getValue() const { return value;}
};


class Dict{
    private:
        int size;
        int count;
        vector<list<HashNode>> table;

        int hashFunction(const string& key) const {
            int intLength = key.length() / 4;
            unsigned long sum = 0;
            
            for (int i = 0; i < intLength; i++) {
                string sub = key.substr(i * 4, 4);
                unsigned long mult = 1;
                for (int j = 0; j < 4; j++) {
                    sum += sub[j] * mult;
                    mult *= 256;
                }
            }
            
            string sub = key.substr(intLength * 4);
            unsigned long mult = 1;
            for (size_t j = 0; j < sub.length(); j++) {
                sum += sub[j] * mult;
                mult *= 256;
            }
            
            return abs(static_cast<int>(sum)) % size;
        }

    public:
        Dict(int size) : size(size), count(0){
            table.resize(size);
        }

        string find(const string& key) const {
            int pos = hashFunction(key);
            
            if(table[pos].empty())
            {
                return "eh";
            }

            for(const auto& node : table[pos])
            {
                if(node.getKey() == key){
                    return node.getValue();
                }
            }

            return "eh";
        }

        void insert(const string& key,const string& value){
            int pos = hashFunction(key);

            for(const auto& node : table[pos])
            {
                if(node.getKey() == key){
                    return;
                }
            }

            table[pos].emplace_back(key, value);
            count++;
        }
};


int main(){
    string line,key, value, word;

    int size = 150007;
    Dict dict(size);
    

    while(getline(cin, line) && !line.empty()){
        size_t pos = line.find(' ');
        key = line.substr(pos + 1);
        value = line.substr(0, pos);
        dict.insert(key, value);
    }


    while(cin >> word){
        string translate = dict.find(word);
        if(translate == "eh")
        {
            cout << "eh" << endl;
        }
        else
        {
            cout << translate << endl;
        }
    }

    return 0;
}


