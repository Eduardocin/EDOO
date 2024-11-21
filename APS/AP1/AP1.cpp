#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Digite um número inteiro: ";
    cin >> num;

    if (cin.fail()) { // Verifica se houve falha na entrada
        cout << "Entrada inválida! Limpando o estado de erro..." << endl;
        cin.clear(); // Limpa o estado de erro
    }

    // Após limpar o estado, podemos pedir outro valor
    cout << "Digite novamente: ";
    cin >> num;

    cout << "Número digitado: " << num << endl;

    return 0;
}
