#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Cabeçalho da tabela
    cout << setw(4) << " "; // Espaço vazio na ponta esquerda
    for (int j = 1; j <= 10; j++) {
        cout << setw(4) << j;
    }
    cout << endl;

    // // Tabela de multiplicação de 1 a 10
    // for (int i = 1; i <= 10; i++) {
    //     cout << setw(4) << i; // Primeira coluna com o número da linha
    //     for (int j = 1; j <= 10; j++) {
    //         cout << setw(4) << i * j; // Define a largura de cada coluna para 4 caracteres
    //     }
    //     cout << endl; // Nova linha após cada linha da tabela
    // }

    return 0;
}