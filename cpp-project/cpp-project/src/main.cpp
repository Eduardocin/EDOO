#include <iostream>
#include "BinaryOperatorNode.h"
#include "LiteralNode.h"

int main() {
    // Criando um nó literal com valor 3
    LiteralNode<double>* three = new LiteralNode<double>(3.0);

    // Criando um nó literal com valor 2
    LiteralNode<double>* two = new LiteralNode<double>(2.0);

    // Criando um nó de operador binário para a divisão
    BinaryOperatorNode* division = new BinaryOperatorNode(three, two, '/');	

    // Avaliando a expressão
    double result = division->evaluate();

    // Exibindo o resultado
    std::cout << "Resultado da expressão 3 / 2: " << result << std::endl;

    // Liberando a memória
    delete three;
    delete two;
    delete division;

    return 0;
}