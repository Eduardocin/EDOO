// LiteralNode.h
#ifndef LITERALNODE_H
#define LITERALNODE_H

#include "AbstractNode.h"

template <typename T>
class LiteralNode : public AbstractNode {
private:
    T value;

public:
    LiteralNode(T value) : value(value) {}

    virtual double evaluate() const override {
        if constexpr (std::is_same_v<T, bool>) {
            return value ? 1.0 : 0.0;
        } else {
            return static_cast<double>(value);
        }
    }

    // Método para obter o valor do literal
    std::pair<T, std::string> getValue() const {
        return {value, typeid(T).name()};
    }
};

#endif // LITERALNODE_H