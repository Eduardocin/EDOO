#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
ListArray<T>::ListArray(int capacity): capacity(capacity), size(0), curr(0){
    array = new T[capacity];
}

template<typename T>
ListArray<T>::~ListArray(){
    delete[] array;
}

template<typename T>
void ListArray<T>::insert(T& Element){
    try{
        if(size >= capacity){
            throw std::out_of_range("List is full");
        }
        int i = size;
        while(i > curr){
            array[i] = array[i-1];
            i--;
        }
        array[curr] = Element;
        size++;
    }
    catch(std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }

}