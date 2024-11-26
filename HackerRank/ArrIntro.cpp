#include <iostream>
using namespace std;


/*
Definition of array: An array is a collection of items stored at contiguous memory locations. 
The idea is to store multiple items of the same type together. 
This makes it easier to calculate the position of each element by simply adding an offset to 
a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array).

*/

inline void reverse(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int size;

    // enter the number os objects in the array
    cin >> size;
    // create an array of size 'size'
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        // enter the elements of the array
        cin >> arr[i];
    }
    
    reverse(arr, size);

    for(int i = 0; i < size; i++){
        // print the elements of the array
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}