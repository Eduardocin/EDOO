#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        string name;
        int age;
    public:
        virtual void getdata(string name, int age) = 0;
        virtual void putdata() = 0;
        virtual ~Person() = default; // Adiciona um destrutor virtual
};

//inhiretance from Person
class Professor: public Person {
    private:
        int publications;
        int cur_id;
        static int id_counter;
    public:
        Professor(){
            cur_id = ++id_counter;
        }

        void getdata(string name, int age) override {
            this->name = name;
            this->age = age;
            cin >> publications;
        }

        void putdata() const override {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};

int Professor::id_counter = 0;

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    static int id_counter;
public:
    Student() {
        cur_id = ++id_counter;
    }

    void getdata(string name, int age) override {
        this->name = name;
        this->age = age;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    void putdata() override {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

int Student::id_counter = 0;

int main() {
    int n, val;
    cin >> n; // Number of objects to be created
    Person* persons[n];

    for (int i = 0; i < n; i++) {
        cin >> val;
        string name;
        int age;
        cin >> name >> age;
        if (val == 1) {
            // If val is 1, create a Professor object
            persons[i] = new Professor();
        } else {
            // If val is 2, create a Student object
            persons[i] = new Student();
        }
        persons[i]->getdata(name, age); // Call getdata to read data
    }

    for (int i = 0; i < n; i++) {
        persons[i]->putdata(); // Call putdata to print data
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete persons[i];
    }

    return 0;
}
