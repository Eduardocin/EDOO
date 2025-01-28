#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
class ListArray{
    private:
        T* array;
        int size;
        int capacity;
        int curr;

    public:
        ListArray(int capacity);
        ~ListArray();
        void insert(const T& element);
        void remove(int index);
        T& get(int index);
        int getSize() const;
        int getCapacity() const;
        void print() const;
}