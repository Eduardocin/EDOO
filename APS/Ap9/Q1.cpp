#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;



/*
Data Type : is a type along with the operations that can be performed on it.
Abstract Data Type : In c++ is a interface that specifies a list of operations that can be performed on a data type.
Data Struct : Is a concrete implementation of an Abstract Data Type.

List implementation using arrays

Operations :
    void clear() - clears the list
    void insert(T value);
    void append(T value);
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int pos);
    T getValue();

*/

class List{
    private :
        int maxSize;
        int curr;
        int listSize;
        int* listArray;
    public :

        List(int size){
            maxSize = size;
            listArray = new int[maxSize];
            curr = 0;
            listSize = 0;
        }

        void insert(int& value){
            
            if(listSize >= maxSize)
            {
                return;
            }

            int i = listSize;      
            while(i > curr)
            {
                listArray[i] = listArray[i-1];
                i--;
            }
            listArray[curr] = value;
            listSize++;
        }
        
        int remove() {
            if(curr < 0 || curr >= listSize){
                return -1;
            }

            int value = listArray[curr]; int i = curr;
            
            while(i < listSize-1)
            {
                listArray[i] = listArray[i+1];
                i++;
            }

            listSize--;
            return value;
        }


        void moveToStart(){
            curr = 0;
        }

        void moveToEnd(){
            curr = listSize;
        }

        void prev(){
            if(curr != 0)
            {
                curr--;
            }
        }

        void next(){
            if(curr < listSize)
            {
                curr++;
            }
        }

        int count(const int& value){
            int count = 0;
            for(int i = 0; i < listSize; i++){
                if(listArray[i] == value){
                    count++;
                }
            }
            return count;
        }


};



int main(){
    int c; // cases
    int n; // number of operations
    string op; // operation
    int value; // value
    
    cin >> c;
    cin.ignore(); // ignore the newline character
    
    while(n--){
        cin >> n;
        List list(n);

        for(int i = 0; i < n; i++){
            cin >> op;
            if(op == "insert"){
                cin >> value;
                list.insert(value);
            }
            else if(op == "count"){
                //count number of elements equal to value
                cin >> value;
                cout << list.count(value) << endl;
            }
            else if(op == "remove"){
                list.remove();
            }
            else if(op == "next"){
                list.next();
            }
            else if(op == "prev"){
                list.prev();
            }
        }

    }

    
    
    return 0;

}