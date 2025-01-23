#include <iostream>
#include "parser.h"
#include "expressions.h"

using namespace std;

int main() {
    int num_inputs;
    cin >> num_inputs;
    cin.ignore();

    if(num_inputs > 0)
    {
        while (num_inputs--) {
            string expression;
            getline(cin, expression);

            try {
                Parser parser(expression);
                Expression* exp = parser.parse_expression();

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
            catch (...) {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}