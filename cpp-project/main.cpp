#include <iostream>
#include <limits>
#include "parser.h"
#include "expressions.h"

using namespace std;


int main() {
    
    int num_inputs;
    cin >> num_inputs;
    
    int max = numeric_limits<int>::max();
    cin.ignore(max, '\n');

    
    while (num_inputs--) {
        string expression;
        getline(cin, expression);

        try {
            Parser parser(expression);
            if(Parser::balancedParentheses(expression)==false) {
                throw std::runtime_error("error");
            }

            Expression* exp = parser.parse_exp();
                try {
                    int intResult = exp->evaluateInt();
                    cout << intResult << endl;
                } 
                catch (const runtime_error&) {
                    bool boolResult = exp->evaluateBool();
                    cout << boolalpha << boolResult << endl;
                }
                delete exp;
            }
        catch(const char* e) {
            cout << "error" << endl;
        }
        catch (...) {
            cout << "error" << endl;
        }
    }
    
    return 0;
}