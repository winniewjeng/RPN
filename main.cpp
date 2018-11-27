#include "SimpleList.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"
#include "ShuntingYard.hpp"

double Eval(Queue<Token*> postfix);
void test_eval();

using namespace std;

int main(int argc, const char * argv[]) {
    
//    test_eval();
    
    string expression;
    cout << "Enter the operation: ";
    cin >> expression;
    cout << "the string expression is " << expression << endl;
    Queue<Token*> infix = toToken(expression);
    cout << "the infix expression is " << infix << endl;
    Queue<Token*> postfix = toPostFix(infix);
    cout << "the postfix expression is " << postfix << endl;
    cout << "the evaluated postfix expression is " << Eval(postfix) << endl;
    return 0;
}

double Eval(Queue<Token*> postfix) {
    //a stack that stores double* Operands
    Stack<double> s;
    
    while (!postfix.empty()) {
        //get the top Token* in the queue
        Token* p = postfix.top();
        //cout << p << " ";
        double LHS;
        double RHS;
        // if Token* is of type Operand(0), i.e. number digit, push into stack
        // if Token* is of type Operator(1), pop stack twice and do the math
        if (p->get_type() == 0) {
            // cast the Token* p to Operand*
            Operand* token_num = static_cast<Operand*>(p);
            // get the value that Operand* holds
            double num = token_num->get_num();
            // push the value into stack
            s.push(num);
        } else {
            // get two numbers from stack
            RHS = s.pop();
            LHS = s.pop();
            // do math with the numbers
            double result = static_cast<Operator*>(p)->do_math(LHS, RHS);
            // push result back into the stack
            s.push(result);
        }
        // house keeping - shrink the postfix queue
        postfix.pop();
    }
    
    return s.top();
};

void test_eval() {
    
    Queue<Token*> input;
    
    input.push(new Operand(3.0));
    input.push(new Operand(2));
    input.push(new Operand(5.5));
    input.push(new Operator("+"));
    input.push(new Operand(4));
    input.push(new Operator("/"));
    input.push(new Operator("*"));
    
    cout << "Evaluate: " << endl;
    cout << input << " = " << Eval(input) << endl;
};

