#include <iostream>

using namespace std;

int* splice(int* arr1, int len1, int* arr2, int len2, int pos) {
    // Allocate memory for the new array
    int* newArr = new int[len1 + len2];

    // Copy elements from the first array up to the given position
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr1[i];
    }

    // Copy all elements from the second array
    for (int i = 0; i < len2; i++) {
        newArr[pos + i] = arr2[i];
    }

    // Copy the remaining elements from the first array
    for (int i = pos; i < len1; i++) {
        newArr[len2 + i] = arr1[i];
    }

    return newArr;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int pos = 2;

    int* newArr = splice(arr1, len1, arr2, len2, pos);

    // Print the new array
    for (int i = 0; i < len1 + len2; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] newArr;

    return 0;
}