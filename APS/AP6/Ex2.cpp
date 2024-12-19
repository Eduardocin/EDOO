#include <iostream>
#include <cstdarg>

using namespace std;

// Função para encontrar o valor mínimo entre um número variável de argumentos
unsigned int min(unsigned int arg1, ...) {
    va_list args; // Declaração da lista de argumentos
    va_start(args, count); // Inicialização da lista de argumentos

    cout << "count :" << count << endl;
    // Inicializa minValue com o primeiro argumento
    unsigned int minValue = va_arg(args, unsigned int);

    cout << "teste" << minValue << endl;

    for (unsigned int i = 1; i < count; ++i) {
        unsigned int value = va_arg(args, unsigned int); // Obtém o próximo argumento
        if (value == 0) break; // Se o valor for 0, termina a iteração
        if (value < minValue) { // Atualiza minValue se encontrar um valor menor
            minValue = value;
        }
    }

    va_end(args); // Limpa a lista de argumentos
    return minValue; // Retorna o menor valor encontrado
}

int main() {
    // Teste da função min com alguns valores de exemplo
    cout << "Minimum value: " << min(5, 10, 20, 5, 15, 0) << endl;

    return 0;
}