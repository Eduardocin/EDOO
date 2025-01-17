#include "LiteralNode.h"

// Construtor que inicializa o valor do literal
LiteralNode::LiteralNode(double value) : value(value) {}

// Método que retorna o valor do literal
double LiteralNode::evaluate() const {
    return value;
}

// Método que define o valor do literal
void LiteralNode::setValue(double value) {
    this->value = value;
}

// Método que obtém o valor do literal
double LiteralNode::getValue() const {
    return value;
}