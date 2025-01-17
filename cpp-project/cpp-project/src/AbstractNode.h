// AbstractNode.h
#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H
#include <string>

class AbstractNode {
public:
    // Construtor padrão
    AbstractNode() = default;

    virtual ~AbstractNode() = default;
    
    // Método puro para avaliação da expressão
    virtual double evaluate() const = 0;
};

#endif // ABSTRACTNODE_H