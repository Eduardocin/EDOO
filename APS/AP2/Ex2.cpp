#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char ch;
    string word;

    cout << "Les't go ! Press the return key: ";
    cin  >> ch;
    cin.ignore(1000, '\n');
    cout << "Enter a word containing three characters at most: ";
    getline(cin, word);
    if(word.length() > 3){
        word = word.substr(0, 3);
    }
    cout << "Your input: " << ch << endl;
    cout << "Word: " << word << endl;


    return 0;
}