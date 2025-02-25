#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

// Classe para representar um nó da tabela de dispersão
template<typename K, typename V>
class HashNode {
private:
    K key;   // Chave
    V value; // Valor
public:
    HashNode(K k, V v) : key(k), value(v) {}
    K getKey() const { return key; }
    V getValue() const { return value; }
};

template<typename K, typename V>
class HashTable {
private:
    int capacity; // Capacidade da tabela
    int size;     // Número de elementos inseridos
    vector<list<HashNode<K, V>>> table; // Vetor de listas de HashNode

    int hashFunction(K key) {
        return key % 10; // Função de dispersão: h(k) = k mod 10
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.assign(capacity, list<HashNode<K,V>>());
    }

    void insert(K key, V value) {
        // Verifica se a chave já existe
        try {
            find(key);
            return; // Se a chave já existe, não insere
        } catch (const runtime_error&) {
            // Chave não encontrada, prossegue com a inserção
        }
        int pos = hashFunction(key);
        table[pos].push_back(HashNode<K,V>(key, value));
        size++;
    }

    V find(K key) {
        int index = hashFunction(key);
        for (const auto &node : table[index]) {
            if (node.getKey() == key) {
                return node.getValue();
            }
        }
        throw runtime_error("Chave não encontrada");
    }

    void remove(K key) {
        int index = hashFunction(key);
        auto &nodeList = table[index];
        for (auto it = nodeList.begin(); it != nodeList.end(); ++it) {
            if (it->getKey() == key) {
                nodeList.erase(it);
                size--;
                return;
            }
        }
        throw runtime_error("Chave não encontrada");
    }

    void clear() {
        table.assign(capacity, list<HashNode<K,V>>());
        size = 0;
    }

    int getSize() const {
        return size;
    }

    void printTable() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (const auto &node : table[i]) {
                cout << node.getKey() << " ";
            }
            cout << endl;
        }
    }
};

class Application {
private:
    HashTable<int, int> dict;

    void readEntries() {
        int numEntries;
        cout << "Informe o número de entradas: ";
        cin >> numEntries;
        cout << "Insira as chaves:" << endl;
        for (int i = 0; i < numEntries; i++) {
            int key;
            cin >> key;
            // Para este exemplo, o valor é igual à chave
            dict.insert(key, key);
        }
    }

    void displayResults() {
        cout << "\nTabela de dispersão:" << endl;
        dict.printTable();
    }

public:
    Application(int capacity) : dict(capacity) {}

    void run() {
        readEntries();
        displayResults();
    }
};

int main() {
    Application app(10);
    app.run();
    return 0;
}