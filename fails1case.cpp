#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>

using namespace std;

// Base Expression class
class Expression {
public:
	virtual ~Expression() {}
	virtual int evaluate() const = 0; // Evaluate integer expression
	virtual bool evaluateBool() const = 0; // Evaluate bool expression
};

// Primary Expression class
class PrimaryExpression : public Expression {
public:
	virtual ~PrimaryExpression() {}
};

// Literal Expression class
class LiteralExpression : public PrimaryExpression {
private:
	int value;
	bool valueBool;
	bool isBool;

public:
	LiteralExpression(int val) : value(val), valueBool(false), isBool(false) {}
	LiteralExpression(bool val) : value(0), valueBool(val), isBool(true) {}

	int evaluate() const override {
		if (isBool) throw std::runtime_error("Invalid operation for integer");
		return value;
	}

	bool evaluateBool() const override {
		if (!isBool) throw std::runtime_error("Invalid operation for boolean");
		return valueBool;
	}
};

// Unary Expression class
class UnaryExpression : public PrimaryExpression {
private:
	char op;
	PrimaryExpression* expr;

public:
	UnaryExpression(char oper, PrimaryExpression* expression) : op(oper), expr(expression) {}

	~UnaryExpression() {
		delete expr;
	}

	int evaluate() const override {
		if (op == '-') {
			return -expr->evaluate();
		}
		// Handle other unary operators if needed
		return expr->evaluate();
	}

	bool evaluateBool() const override {
		// Handle unary boolean operations if needed
		return expr->evaluateBool();
	}
};

// Multiplicative Expression class
class MulExpression : public Expression {
private:
	Expression* left;
	char op;
	Expression* right;

public:
	MulExpression(Expression* lhs, char oper, Expression* rhs) : left(lhs), op(oper), right(rhs) {}

	~MulExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		if (op == '*') {
			return left->evaluate() * right->evaluate();
		}
		else if (op == '/') {
			return left->evaluate() / right->evaluate();
		}
		throw std::runtime_error("Invalid operator");
	}

	bool evaluateBool() const override {
		throw std::runtime_error("Invalid operation for boolean");
	}
};

// Additive Expression class
class AddExpression : public Expression {
private:
	Expression* left;
	char op;
	Expression* right;

public:
	AddExpression(Expression* lhs, char oper, Expression* rhs) : left(lhs), op(oper), right(rhs) {}

	~AddExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		if (op == '+') {
			return left->evaluate() + right->evaluate();
		}
		else if (op == '-') {
			return left->evaluate() - right->evaluate();
		}
		throw std::runtime_error("Invalid operator");
	}

	bool evaluateBool() const override {
		throw std::runtime_error("Invalid operation for boolean");
	}
};

// Relational Expression class
class RelExpression : public Expression {
private:
	Expression* left;
	std::string op;
	Expression* right;

public:
	RelExpression(Expression* lhs, const std::string& oper, Expression* rhs) : left(lhs), op(oper), right(rhs) {}

	~RelExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		throw std::runtime_error("Invalid operation for integer");
	}

	bool evaluateBool() const override {
		if (op == "<") {
			return left->evaluate() < right->evaluate();
		}
		else if (op == ">") {
			return left->evaluate() > right->evaluate();
		}
		else if (op == "<=") {
			return left->evaluate() <= right->evaluate();
		}
		else if (op == ">=") {
			return left->evaluate() >= right->evaluate();
		}
		throw std::runtime_error("Invalid operator");
	}
};

// Equality Expression class
class EqExpression : public Expression {
private:
	Expression* left;
	std::string op;
	Expression* right;

public:
	EqExpression(Expression* lhs, const std::string& oper, Expression* rhs) : left(lhs), op(oper), right(rhs) {}

	~EqExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		throw std::runtime_error("Invalid operation for integer");
	}

	bool evaluateBool() const override {
		if (op == "==") {
			return left->evaluateBool() == right->evaluateBool();
		}
		else if (op == "!=") {
			return left->evaluateBool() != right->evaluateBool();
		}
		throw std::runtime_error("Invalid operator");
	}
};

// And Expression class
class AndExpression : public Expression {
private:
	Expression* left;
	Expression* right;

public:
	AndExpression(Expression* lhs, Expression* rhs) : left(lhs), right(rhs) {}

	~AndExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		throw std::runtime_error("Invalid operation for integer");
	}

	bool evaluateBool() const override {
		return left->evaluateBool() && right->evaluateBool();
	}
};

// Or Expression class
class OrExpression : public Expression {
private:
	Expression* left;
	Expression* right;

public:
	OrExpression(Expression* lhs, Expression* rhs) : left(lhs), right(rhs) {}

	~OrExpression() {
		delete left;
		delete right;
	}

	int evaluate() const override {
		throw std::runtime_error("Invalid operation for integer");
	}

	bool evaluateBool() const override {
		return left->evaluateBool() || right->evaluateBool();
	}
};

// Expression class
class Exp : public Expression {
private:
	Expression* expr;

public:
	Exp(Expression* expression) : expr(expression) {}

	~Exp() {
		delete expr;
	}

	int evaluate() const override {
		return expr->evaluate();
	}

	bool evaluateBool() const override {
		return expr->evaluateBool();
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
		}
		else if (isalpha(input[pos])) {
			size_t start = pos;
			while (pos < input.size() && isalpha(input[pos])) ++pos;
			curToken = input.substr(start, pos - start);
		}
		else {
			curToken = input[pos++];
		}
	}

	Expression* parsePrimary() {
		
		if (curToken == "(") {
			getNextToken();
			Expression* expr = parseExp();
			if(curToken == ")") {
				getNextToken();
			}
			return new Exp(expr);
		}
		
		if (curToken == "true" || curToken == "false") {
			bool value = (curToken == "true");
			getNextToken();
			return new LiteralExpression(value);
		}
		else if (isdigit(curToken[0])) {
			int value = stoi(curToken);
			getNextToken();
			return new LiteralExpression(value);
		}

		throw runtime_error("Invalid primary expression");
	}

	Expression* parseUnaryExp() {
		if (curToken == "-") {
			string op = curToken;
			getNextToken();
			return new UnaryExpression(op[0], dynamic_cast<PrimaryExpression*>(parseUnaryExp()));
		}
		return parsePrimary();
	}

	Expression* parseMulExp() {
		Expression* left = parseUnaryExp();
		while (curToken == "*" || curToken == "/") {
			string op = curToken;
			getNextToken();
			Expression* right = parseUnaryExp();
			left = new MulExpression(left, op[0], right);
		}
		return left;
	}

	Expression* parseAddExp() {
		Expression* left = parseMulExp();
		while (curToken == "+" || curToken == "-") {
			string op = curToken;
			getNextToken();
			Expression* right = parseMulExp();
			left = new AddExpression(left, op[0], right);
		}
		return left;
	}

	Expression* parseRelExp() {
		Expression* left = parseAddExp();
		while (curToken == "<" || curToken == ">" || curToken == "<=" || curToken == ">=") {
			string op = curToken;
			getNextToken();
			Expression* right = parseAddExp();
			left = new RelExpression(left, op, right);
		}
		return left;
	}

	Expression* parseEqExp() {
		Expression* left = parseRelExp();
		while (curToken == "==" || curToken == "!=") {
			string op = curToken;
			getNextToken();
			Expression* right = parseRelExp();
			left = new EqExpression(left, op, right);
		}
		return left;
	}

	Expression* parseAndExp() {
		Expression* left = parseEqExp();
		while (curToken == "&&") {
			getNextToken();
			Expression* right = parseEqExp();
			left = new AndExpression(left, right);
		}
		return left;
	}

	Expression* parseOrExp() {
		Expression* left = parseAndExp();

		while (curToken == "||") {
			getNextToken();
			Expression* right = parseAndExp();
			left = new OrExpression(left, right);
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

// Main function
int main() {
	int num_inputs;
	cin >> num_inputs;
	cin.ignore();

	while (num_inputs--) {
		string input;
		getline(cin, input);

		try {
			cout << "Input: " << input << endl;
			Parser parser(input);
			Expression* expr = parser.parse();
			if (input.find("true") != string::npos || input.find("false") != string::npos || input.find("&&") != string::npos || input.find("||") != string::npos || input.find("==") != string::npos || input.find("!=") != string::npos) {
				cout << "Output: " << (expr->evaluateBool() ? "true" : "false") << endl;
			}
			else {
				cout << "Output: " << expr->evaluate() << endl;
			}
			delete expr;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
	}

	return 0;
}
