#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <myMacros.h> // Inclua o arquivo de cabeçalho com as macros

using namespace std;



int main(){
    int n;

    unsigned int seed; // Alterado de long para unsigned int
    time_t t;
    time(&t);
    seed = (unsigned int)t;
    srand(seed);

    n = (rand() % 15) + 1;

    // try guess the random number in 3 possibilities
    int guess;
    for(int i = 0; i < 3 ; i++){
        cout << "Guess the number between 1 and 15: ";
        cin >> guess;

        if(guess == n){
            cout << "Congratulations! You guessed the number!" << endl;
            return 0;
        }else if(guess < n){
            cout << "The number is greater than " << guess << endl;
        }else{
            cout << "The number is less than " << guess << endl;
        }

        if( i == 2 && guess != n){
            cout << "You lost! The number was " << n << endl;
        }
    }


    return 0;
}