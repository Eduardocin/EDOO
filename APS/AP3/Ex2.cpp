#include <iostream>
#include <string>

using namespace std;

//check if the string is a palindrome
inline bool isPalindrome(string const& s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]){
            return false;
        }
    }
    return true;
}


int main(){
    string input;
    
    cout << "Enter a world to check if it is a palindrome(or 'exit' to quit): " << endl;

    while(input != "exit"){
        getline(cin, input);

        if(input == "exit"){
            break;
        }

        if(isPalindrome(input)){
            cout << "The string is a palindrome" << endl;
        }else{
            cout << "The string is not a palindrome" << endl;
        }
    }

    return 0;
}