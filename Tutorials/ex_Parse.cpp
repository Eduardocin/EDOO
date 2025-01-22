#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

using namespace std;

// Classe base para expressões
class Expression {
public:
	virtual ~Expression() {}

	virtual int evaluateInt() const {
		throw std::runtime_error("Operação não suportada para int");
	}

	virtual bool evaluateBool() const {
		throw std::runtime_error("Operação não suportada para bool");
	}
};

// Classe para operadores
class Operator {
private:
	string op;
public:
	Operator(const string& op) : op(op) {}

	string getOp() const {
		return op;
	}
};

// Template base para Literals
template<typename T>
class Literal : public Expression {
public:
	Literal(T value) : value(value) {}

	// Métodos de avaliação lançam exceções por padrão
	int evaluateInt() const override {
		throw std::runtime_error("Operação não suportada para int");
	}

	bool evaluateBool() const override {
		throw std::runtime_error("Operação não suportada para bool");
	}

protected:
	T value;
};

// Especialização para Literal<int>
template<>
class Literal<int> : public Expression {
private:
	int value;
public:
	Literal(int value) : value(value) {}

	int evaluateInt() const override {
		return value;
	}
};

// Especialização para Literal<bool>
template<>
class Literal<bool> : public Expression {
private:
	bool value;
public:
	Literal(bool value) : value(value) {}

	bool evaluateBool() const override {
		return value;
	}
};

// Classe base para expressões binárias
class BinaryExpression : public Expression {
protected:
	Expression* e1;
	Expression* e2;
	Operator* op;

public:
	BinaryExpression(Expression* e1, Operator* op, Expression* e2) : e1(e1), op(op), e2(e2) {}

	~BinaryExpression() override {
		delete e1;
		delete e2;
		delete op;
	}

	bool evaluateBool() const override {
		if (op->getOp() == "==") {
			// Se os operandos forem booleanos
			return e1->evaluateBool() == e2->evaluateBool();
		}
		// ...demais operadores...
		throw std::runtime_error("Operação inválida");
	}

	int evaluateInt() const override {
		// Caso tente avaliar int para '==', lance erro
		throw runtime_error("Operação não suportada para int.");
	}
};

// Expressão de igualdade
class EqExp : public BinaryExpression {
public:
	EqExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

	bool evaluateBool() const override {
		if (op->getOp() == "==" || op->getOp() == "!=") {
			// Tenta comparar como booleanos
			try {
				bool leftBool = e1->evaluateBool();
				bool rightBool = e2->evaluateBool();
				if (op->getOp() == "==") {
					return leftBool == rightBool;
				}
				else {
					return leftBool != rightBool;
				}
			}
			catch (const std::runtime_error&) {
				// Se falhar, tenta comparar como inteiros
				try {
					int leftInt = e1->evaluateInt();
					int rightInt = e2->evaluateInt();
					if (op->getOp() == "==") {
						return leftInt == rightInt;
					}
					else {
						return leftInt != rightInt;
					}
				}
				catch (const std::runtime_error&) {
					throw std::runtime_error("Operação inválida em EqExp");
				}
			}
		}
		throw std::runtime_error("Operação inválida");
	}
};

// Expressão lógica E
class AndExp : public BinaryExpression {
public:
	AndExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

	bool evaluateBool() const override {
		if (op->getOp() == "&&") {
			return e1->evaluateBool() && e2->evaluateBool();
		}
		throw std::runtime_error("Operação inválida");
	}
};

// Expressão lógica OU
class OrExp : public BinaryExpression {
public:
	OrExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

	bool evaluateBool() const override {
		if (op->getOp() == "||") {
			return e1->evaluateBool() || e2->evaluateBool();
		}
		throw std::runtime_error("Operação inválida");
	}
};

// Expressão relacional
class RelExp : public BinaryExpression {
public:
	RelExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

	bool evaluateBool() const override {
		if (op->getOp() == "<") {
			return e1->evaluateInt() < e2->evaluateInt();
		}
		else if (op->getOp() == ">") {
			return e1->evaluateInt() > e2->evaluateInt();
		}
		else if (op->getOp() == "<=") {
			return e1->evaluateInt() <= e2->evaluateInt();
		}
		else if (op->getOp() == ">=") {
			return e1->evaluateInt() >= e2->evaluateInt();
		}
		throw std::runtime_error("Operação inválida");
	}
};

// Expressão de adição e subtração
class AddExp : public BinaryExpression {
public:
	AddExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

    int evaluateInt() const override {
        try {
            int leftValue = e1->evaluateInt();
            int rightValue = e2->evaluateInt();

            if (op->getOp() == "+") {
                return leftValue + rightValue;
            }
            else if (op->getOp() == "-") {
                return leftValue - rightValue;
            }
        } catch (const std::runtime_error&) {
            throw std::runtime_error("Operação inválida: operandos incompatíveis");
        }
        throw std::runtime_error("Operação inválida");
    }
};

// Expressão de multiplicação e divisão
class MulExp : public BinaryExpression {
public:
	MulExp(Expression* e1, Operator* op, Expression* e2) : BinaryExpression(e1, op, e2) {}

	int evaluateInt() const override {
		if (op->getOp() == "*") {
			return e1->evaluateInt() * e2->evaluateInt();
		}
		else if (op->getOp() == "/") {
			int divisor = e2->evaluateInt();
			if (divisor == 0) {
				throw std::runtime_error("divisão por zero");
			}
			return e1->evaluateInt() / divisor;
		}
		throw std::runtime_error("Operação inválida");
	}
};

// Expressão unária
class UnaryExpression : public Expression {
protected:
	Expression* e;
	Operator* op;

public:
	UnaryExpression(Expression* e, Operator* op) : e(e), op(op) {}
	~UnaryExpression() override { delete e; delete op; }

	int evaluateInt() const override {
		if (op->getOp() == "-") {
			return -e->evaluateInt();
		}
		throw std::runtime_error("Operação unária inválida");
	}

	bool evaluateBool() const override {
		if (op->getOp() == "!") {
			return !e->evaluateBool();
		}
		throw std::runtime_error("Operação unária inválida");
	}
};


class ParenthesesExpression : public Expression {
protected:
	Expression* e;
public:
	ParenthesesExpression(Expression* e) : e(e) {}
	~ParenthesesExpression() override { delete e; }
	
	
	int evaluateInt() const override {
		return e->evaluateInt();
	}
	bool evaluateBool() const override {
		return e->evaluateBool();
	}
};

// Classe Parser para analisar expressões
class Parser {
private:
	
	std::istringstream stream;
	std::string current_token;

	std::string tokenizer() {
		char c;
		while (stream.get(c) && std::isspace(c)) {}

		if (stream.eof()) {
			return "";
		}

		if (std::isdigit(c) || std::isalpha(c)) {
			std::string token(1, c);
			while (stream.peek() != EOF && std::isalnum(stream.peek())) {
				token += static_cast<char>(stream.get());
			}
			return token;
		}

		if (c == '(' || c == ')') {
			return std::string(1, c);
		}

		std::string op(1, c);
		if (stream.peek() != EOF) {
			char next = static_cast<char>(stream.peek());
			if ((op == "=" && next == '=') ||
				(op == "|" && next == '|') ||
				(op == "&" && next == '&') ||
				(op == "!" && next == '=') ||
				(op == "<" && next == '=') ||
				(op == ">" && next == '=')) {
				stream.get();
				return op + next;
			}
		}
		return op;
	}

public:

	// Construtor
	Parser(const std::string& expression) : stream(expression), current_token("") {
		next_token();
	}

	void next_token() {
		current_token = tokenizer();
	}

	std::string curToken() const {
		return current_token;
	}

	Expression* parse_expression() {
		return or_exp();
	}

	Expression* or_exp() {
		Expression* e1 = and_exp();
		while (current_token == "||") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = and_exp();
			e1 = new OrExp(e1, op, e2);
		}
		return e1;
	}

	Expression* and_exp() {
		Expression* e1 = eq_exp();
		while (current_token == "&&") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = eq_exp();
			e1 = new AndExp(e1, op, e2);
		}
		return e1;
	}

	Expression* eq_exp() {
		Expression* e1 = rel_exp();
		while (current_token == "==" || current_token == "!=") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = rel_exp();
			e1 = new EqExp(e1, op, e2);
		}
		return e1;
	}

	Expression* rel_exp() {
		Expression* e1 = add_exp();
		while (current_token == "<" || current_token == ">" || current_token == "<=" || current_token == ">=") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = add_exp();
			e1 = new RelExp(e1, op, e2);
		}
		return e1;
	}

	Expression* add_exp() {
		Expression* e1 = mul_exp();
		while (current_token == "+" || current_token == "-") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = mul_exp();
			e1 = new AddExp(e1, op, e2);
		}
		return e1;
	}

	Expression* mul_exp() {
		Expression* e1 = unary_exp();
		while (current_token == "*" || current_token == "/") {
			Operator* op = new Operator(current_token);
			next_token();
			Expression* e2 = unary_exp();
			e1 = new MulExp(e1, op, e2);
		}
		return e1;
	}

	Expression* unary_exp() {
		if (current_token == "-") {
			Operator* op = new Operator(current_token);
			next_token();
			return new UnaryExpression(unary_exp(), op);
		}
		else if (current_token == "!") {
			Operator* op = new Operator(current_token);
			next_token();
			return new UnaryExpression(unary_exp(), op);
		}
		return primary_exp();
	}

	Expression* primary_exp() {

		// Se for uma expressão entre parênteses
		if (current_token == "(") {
			next_token();
			Expression* e = parse_expression();
			if (current_token == ")") {
				next_token();
			}
			return e; // Retorna expressão entre parênteses
		}
		
		// Se for um literal
		string token = current_token;
		next_token();
		if (token == "true") {
			return new Literal<bool>(true);
		}
		else if (token == "false") {
			return new Literal<bool>(false);
		}
		else {
			return new Literal<int>(stoi(token));
		}
	}
};

int main() {
	int num_inputs;
	cin >> num_inputs;
	cin.ignore();

	while (num_inputs--) {
		string expression;
		getline(cin, expression);
		
		
		try {

			Parser parser(expression);
			Expression* exp = parser.parse_expression();

            try {
                int intResult = exp->evaluateInt();
                cout << intResult << endl;
            } catch (const std::runtime_error&) {
                bool boolResult = exp->evaluateBool();
                cout << boolalpha << boolResult << endl;
            }

			delete exp;
		}
		catch (const std::exception& e) {
            string error = e.what();
			cerr << "error" << endl;
	    }
    }

	return 0;
}
