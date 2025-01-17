#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

// Base Expression class
class Expression {
public:
    virtual ~Expression() {}
    virtual int evaluate() const = 0;  // Evaluate the expression
    virtual bool evaluateBool() const{}

};

// Literal Expression class
class LiteralExpression : public Expression {
    int value;
    bool isBool = false;
public:
    LiteralExpression(int val) : value(val) {}
    int evaluate() const override {
        if (isBool) {
            return value ? true : false;
        }
        return value;
    }
};


// Override the evaluate method to return boolean values as true/false
class BooleanLiteralExpression : public Expression {
    bool value;
public:
    BooleanLiteralExpression(bool val) : value(val) {}
    int evaluate() const override {
        return value;
    }
    bool evaluateBool() const {
        return value;
    }
};

// Unary Expression class
class UnaryExpression : public Expression {
    char op;
    Expression* expr;
public:
    UnaryExpression(char oper, Expression* exp) : op(oper), expr(exp) {}

    ~UnaryExpression() { delete expr; }

    int evaluate() const override {
        int val = expr->evaluate();
        switch (op) {
            case '-': return -val;
            default: throw invalid_argument("Invalid unary operator");
        }
    }
};

// Binary Expression class
class BinaryExpression : public Expression {
    Expression* left;
    Expression* right;
    string op;

public:
    BinaryExpression(Expression* lhs, Expression* rhs, const string& oper) : left(lhs), right(rhs), op(oper) {}
    ~BinaryExpression() { delete left; delete right; }
    int evaluate() const override {
        int leftVal = left->evaluate();
        int rightVal = right->evaluate();
        if (op == "+") return leftVal + rightVal;
        if (op == "-") return leftVal - rightVal;
        if (op == "*") return leftVal * rightVal;
        if (op == "/") {
            if (rightVal == 0) throw runtime_error("Division by zero");
            return leftVal / rightVal;
        }
        if (op == "||") return leftVal || rightVal;
        if (op == "&&") return leftVal && rightVal;
        if (op == "==") return leftVal == rightVal;
        if (op == "!=") return leftVal != rightVal;
        throw invalid_argument("Invalid binary operator");
    }
};

// Parser class
class Parser {
    string input;
    size_t pos;
    string curToken;

    void getNextToken() {
        while (pos < input.size() && isspace(input[pos])) ++pos;
        if (pos == input.size()) {
            curToken = "";
            return;
        }
        if (isdigit(input[pos])) {
            size_t start = pos;
            while (pos < input.size() && isdigit(input[pos])) ++pos;
            curToken = input.substr(start, pos - start);
        } else if (isalpha(input[pos])) {
            size_t start = pos;
            while (pos < input.size() && isalpha(input[pos])) ++pos;
            curToken = input.substr(start, pos - start);
        } else {
            curToken = input[pos++];
        }
    }

    Expression* parsePrimary() {
        if (curToken == "(") {
            getNextToken();
            Expression* expr = parseExp();
            if (curToken != ")") throw runtime_error("Expected ')'");
            getNextToken();
            return expr;
        }
        if (isdigit(curToken[0])) {
            int value = stoi(curToken);
            getNextToken();
            return new LiteralExpression(value);
        }
        if (curToken == "true" || curToken == "false") {
            bool value = (curToken == "true");
            getNextToken();
            return new BooleanLiteralExpression(value);
        }
        throw runtime_error("Invalid primary expression");
    }

    Expression* parseUnaryExp() {
        if (curToken == "-") {
            string op = curToken;
            getNextToken();
            return new UnaryExpression(op[0], parseUnaryExp());
        }
        return parsePrimary();
    }

    Expression* parseMulExp() {
        Expression* left = parseUnaryExp();
        while (curToken == "*" || curToken == "/") {
            string op = curToken;
            getNextToken();
            Expression* right = parseUnaryExp();
            left = new BinaryExpression(left, right, op);
        }
        return left;
    }

    Expression* parseAddExp() {
        Expression* left = parseMulExp();
        while (curToken == "+" || curToken == "-") {
            string op = curToken;
            getNextToken();
            Expression* right = parseMulExp();
            left = new BinaryExpression(left, right, op);
        }
        return left;
    }

    Expression* parseRelExp() {
        Expression* left = parseAddExp();
        while (curToken == "==" || curToken == "!=") {
            string op = curToken;
            getNextToken();
            Expression* right = parseAddExp();
            left = new BinaryExpression(left, right, op);
        }
        return left;
    }

    Expression* parseAndExp() {
        Expression* left = parseRelExp();
        while (curToken == "&&") {
            string op = curToken;
            getNextToken();
            Expression* right = parseRelExp();
            left = new BinaryExpression(left, right, op);
        }
        return left;
    }

    Expression* parseOrExp() {
        Expression* left = parseAndExp();
        while (curToken == "||") {
            string op = curToken;
            getNextToken();
            Expression* right = parseAndExp();
            left = new BinaryExpression(left, right, op);
        }
        return left;
    }

    Expression* parseExp() {
        return parseOrExp();
    }

public:
    Parser(const string& input) : input(input), pos(0) {
        getNextToken();
    }

    Expression* parse() {
        return parseExp();
    }
};

int main() {
    int num_inputs;
    cin >> num_inputs;
    cin.ignore();

    while (num_inputs--) {
        string input;
        getline(cin, input);

        try {
            Parser parser(input);
            Expression* expr = parser.parse();
            cout << expr->evaluate() << endl;
            delete expr;
        } catch (const exception& e) {
            cout << "error" << endl;
        }
    }

    return 0;
}