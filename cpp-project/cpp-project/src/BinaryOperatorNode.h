// BinaryOperatorNode.h
#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include "AbstractNode.h"
#include <stdexcept>

class BinaryOperatorNode : public AbstractNode {
private:
    AbstractNode* leftOperand;   // Operando esquerdo
    AbstractNode* rightOperand;  // Operando direito
    char operation;               // Operador (ex: '+', '-', '*', '/')

public:
    // Construtor
    BinaryOperatorNode(AbstractNode* left, AbstractNode* right, char op)
        : leftOperand(left), rightOperand(right), operation(op) {}

    // Destrutor
    virtual ~BinaryOperatorNode() {
        delete leftOperand;
        delete rightOperand;
    }

    // Método para avaliar a expressão
    double evaluate() const override {
        double leftValue = leftOperand->evaluate();
        double rightValue = rightOperand->evaluate();

        switch (operation) {
            case '+': return leftValue + rightValue;
            case '-': return leftValue - rightValue;
            case '*': return leftValue * rightValue;
            case '/': return leftValue / rightValue;
            default: throw std::invalid_argument("Operador inválido");
        }
    }

    // Métodos para obter os operandos
    AbstractNode* getLeftOperand() const { return leftOperand; }
    AbstractNode* getRightOperand() const { return rightOperand; }

    // Métodos para definir os operandos
    void setLeftOperand(AbstractNode* left) { leftOperand = left; }
    void setRightOperand(AbstractNode* right) { rightOperand = right; }
};

#endif // BINARYOPERATORNODE_H