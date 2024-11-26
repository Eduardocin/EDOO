#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

// define an array-based list class
template <typename E>
class ArrayBasedList {
private:
    int maxSize;
    int size;
    int curr;
    unique_ptr<E[]> array;

public:
    // constructor
    ArrayBasedList(int numElements) {
        maxSize = numElements;
        size = curr = 0;
        array = make_unique<E[]>(maxSize);
    }

    ~ArrayBasedList() = default;

    inline void insert(const E& value) {
            // check if the list is full
        if (size >= maxSize) {
            throw overflow_error("List is full");
        }

        // put the elements to the right of the current element one position to the right
        for (int i = size; i > curr; --i) {
            array[i] = move(array[i - 1]);
        }

        // insert the new element
        array[curr] = value;
        size++;
    }

    inline void next() {
        if (curr < size - 1) {
            curr++;
        }
    }

    inline void prev() {
        if (curr > 0) {
            curr--;
        }
    }

    inline int count(const E& value) const {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                count++;
            }
        }
        return count;
    }

    E remove() {
        if ((curr < 0) || (curr >= size)) {
            throw std::runtime_error("Index out of bounds");
        }
        int i = curr;
        E it = array[curr];
        while (i < size - 1) {
            array[i] = array[i + 1];
            i++;
        }
        size--;
        return it;
    }

    E get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    int getsize() const {
        return size;
    }

    E operator[](int index) const {
        return get(index);
    }
};

int main() {
    int c;
    cin >> c;

    for (int caseNum = 1; caseNum <= c; caseNum++) {
        int n;
        cin >> n;

        auto arr = make_unique<ArrayBasedList<int>>(n);

        cout << "Caso " << caseNum << ":" << endl;

        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;

            if (command == "insert") {
                int value;
                cin >> value;
                arr->insert(value);
            } else if (command == "remove") {
                arr->remove();
            } else if (command == "count") {
                int value;
                cin >> value;
                cout << arr->count(value) << endl;
            } else if (command == "prev") {
                arr->prev();
            } else if (command == "next") {
                arr->next();
            }
        }
    }

    return 0;
}