#include <iostream>

using namespace std;

template<typename T>
class Array {
    private:
        T *ptr;
        int size;
    public:
        Array(T arr[], int s);
        void print() const;
};

// Implementação do construtor
template<typename T>
Array<T>::Array(T arr[], int s) {
    size = s;
    ptr = new T[s];
    for (int i = 0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

// Implementação da função print
template<typename T>
inline void Array<T>::print() const {
    for (int i = 0; i < size; i++) {
        cout << " " << ptr[i];
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};


    Array<int>* a = new Array<int>(arr, 5);

    a->print();
    
    return 0;
}