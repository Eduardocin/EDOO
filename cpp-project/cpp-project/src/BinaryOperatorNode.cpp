// BinaryOperatorNode.cpp
#include "BinaryOperatorNode.h"

BinaryOperatorNode::BinaryOperatorNode(AbstractNode* left, AbstractNode* right, char op)
    : leftOperand(left), rightOperand(right), operatorSymbol(op) {}

BinaryOperatorNode::~BinaryOperatorNode() {
    delete leftOperand;
    delete rightOperand;
}

double BinaryOperatorNode::evaluate() const {
    double leftValue = leftOperand->evaluate();
    double rightValue = rightOperand->evaluate();

    switch (operatorSymbol) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                throw std::runtime_error("Division by zero");
            }
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

void BinaryOperatorNode::setLeftOperand(AbstractNode* left) {
    leftOperand = left;
}

void BinaryOperatorNode::setRightOperand(AbstractNode* right) {
    rightOperand = right;
}

AbstractNode* BinaryOperatorNode::getLeftOperand() const {
    return leftOperand;
}

AbstractNode* BinaryOperatorNode::getRightOperand() const {
    return rightOperand;
}