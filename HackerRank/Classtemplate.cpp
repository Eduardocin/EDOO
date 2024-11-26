#include <iostream>
#include <string>
using namespace std;

template <class T>
class AddElements {
private:
    T element;
public:
    AddElements(const T& arg) : element(arg) {}

    inline T add(const T& val2) {
        return element + val2;
    }
};

template <>
class AddElements<string> {
private:
    string element;
public:
    AddElements(const string& arg) : element(arg) {}

    inline string add(const string& val2) {
        return element + val2;
    }
};

int main() {
    int n;
    // número de entradas
    cin >> n;

    for (int i = 0; i < n; i++) {
        // tipo de entrada
        string type;
        cin >> type;

        if (type == "float") {
            float element1, element2;
            cin >> element1 >> element2;
            AddElements<float> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        } else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        } else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.add(element2) << endl;
        }
    }

    return 0;
}