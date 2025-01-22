#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include "expressions.h"

class Parser {
private:
    std::istringstream stream;
    std::string current_token;

    std::string tokenizer();
    void next_token();

    Expression* or_exp();
    Expression* and_exp();
    Expression* eq_exp();
    Expression* rel_exp();
    Expression* add_exp();
    Expression* mul_exp();
    Expression* unary_exp();
    Expression* primary_exp();

public:
    Parser(const std::string& expression);
    Expression* parse_expression();
    std::string curToken() const;
};

#endif
