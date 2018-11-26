#include "SimpleList.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"
#include "ShuntingYard.hpp"

//evaluate the rpn expression
double Eval(Queue<Token*> postfix);
////parse the user-input string into tokens and store them in queue
//Queue<Token*> toToken(string expression);
////convert the infix queue to a post-fix queue using Shunting-Yard algorithm
//Queue<Token*> toPostFix(Queue<Token*> infix);
// check if eval is working
void test_eval();

using namespace std;

int main(int argc, const char * argv[]) {
    
    //    test_eval();
    
    string expression;
    cout << "Enter the operation: ";
    cin >> expression;
    cout << "the string expression is " << expression << "!"<< endl;
    Queue<Token*> infix = toToken(expression);
    cout << "the infix expression is " << infix << endl;
    Queue<Token*> postfix = toPostFix(infix);
    cout << "the postfix expression is " << postfix << endl;
    return 0;
    
    /*
     attack plan:
     //get a populated queue of infix tokens
     //shunting-yard alogrithm
     //get an emptry queue of postfix tokens
     //get a stack of operator tokens
     //if it's a number, add it to the output
     //if it's an operator, check precedence
     //if precedence is correct, push it to the stack
     //if not, add it pop a stack to the postfix queue and push operator to stack
     //keep doing it until stack operator tokens has no more element
     */
}

//// convert user input string to token and then store queue
//Queue<Token*> toToken(string expression) {
//    string num_str;
//    string optr_str; // operator string
//    Queue<Token*> infix;
//    
//    for (int i = 0; i < expression.size(); i++) {
//        // if the element in string is a digit, get the whole number and push it to Queue
//        if (isdigit(expression[i]) || expression[i] == '.') {
//            //form operand
//            while (isdigit(expression[i]) || expression[i] == '.') {
//                num_str += expression[i];
//                i++;
//            }
//            double number = stod(num_str);
//            infix.push(new Operand(number));
//            // reset the num_str for clean reading of the next number
//            num_str="";
//        }
//        
//        // if the element in string is an operator, get the operator and push it to Queue
//        if (!isdigit(expression[i]) && !isalpha(expression[i])) {
//            optr_str += expression[i];
//            infix.push(new Operator(optr_str));
//            // reset the optr_str for clean reading of the next operator
//            optr_str = "";
//        }
//        
//        // if the item in string is a trig, get the whole trig and push it to Queue
//        // note that in the queue, trig tends to leave out an open paraenthesis
//        if (isalpha(expression[i])) {
//            while(isalpha(expression[i])) {
//                optr_str += expression[i];
//                i++;
//            }
//            infix.push(new Operator(optr_str));
//            // reset the optr_str for clean reading of the next operator
//            optr_str = "";
//        }
//        
//    }
//    return infix;
//}

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

//// turn the infix to postfix
//Queue<Token*> toPostFix(Queue<Token*> infix) {
//    // get a postfix queue
//    Queue<Token*> postfix;
//    // get an operator stack
//    Stack<Operator*> optr;
//    
//    while (!infix.empty()) {
//        //pop infix queue one item at a time
//        Token* item = infix.pop();
////        cout << "infix.pop() item is ";
//        // if item is a number-->push item into the postfix queue
//        if (item->get_type() == 0) {
////            cout << item << " 0" << endl;
//            postfix.push(item);
//        }
//        // if item is not a number-->check for precedence before action
//        else {
//            // typecast item from token to operator
//            Operator* optr_item = static_cast<Operator*>(item);
//            // if optr stack is empty, push optr_item straight in
//            if (optr.empty()) {
////                cout << item << " 1" << endl;
//                // if stack is empty-->push optr_item into the stack
//                optr.push(optr_item);
////                cout << "optr stack is " << optr << endl;
////                cout << "postfix queue is " << postfix << endl;
//            }
//            // if optr stack is not empty, check for paranthesis and then general precedence
//            else {
////                cout << item << " 2" << endl;
//                // if optr_item (popped from infix queue) is a closed paranthesis,
//                if (optr_item->get_symb() == ")" ) {
//                    // then pop the stack & store each item in the postfix queue until finding the open parenthesis
//                    while (optr.top()->get_symb() != "(" && !optr.empty()) {
//                        //pop the stack and store them to postfix queue
//                        postfix.push(optr.pop());
//                    }
//                    // then finally, pop the open parenthesis
//                    optr.pop();
//                }
//                // if optr_item (popped from infix queue) is stacked on top of another operator with higher order of precedence
//                else if (optr_item->has_precedence(optr.top())) {
//                    // then pop stack & push the popped into postfix queue
//                    postfix.push(optr.pop());
//                    // and then push optr_item into optr stack
//                    optr.push(optr_item);
//                }
//                // if optr_item is not a closed parenthesis or has no higher precedence, just push it into the optr stack
//                else {
//                    optr.push(optr_item);
//                }
////                cout << "optr stack is " << optr << endl;
////                cout << "postfix queue is " << postfix << endl;
//            }
//        }
//        
//        // if infix queue has become empty, push everything in the optr stack into postfix queue
//        if (infix.empty()) {
//            while(!optr.empty()) {
//                postfix.push(optr.pop());
//            }
//        }
//    }
//    
//    return postfix;
//}

void test_eval() {
    
    Queue<Token*> input;
    
    input.push(new Operand(4));
    input.push(new Operand(2));
    input.push(new Operator("+"));
    input.push(new Operand(5));
    input.push(new Operator("*"));
    
    cout << "Evaluate: " << endl;
    cout << input << " = " << Eval(input) << endl;
    
    Queue<Token*> input2;
    
    input2.push(new Operand(8));
    input2.push(new Operand(3));
    input2.push(new Operator("*"));
    input2.push(new Operand(6));
    input2.push(new Operator("/"));
    input2.push(new Operand(2));
    input2.push(new Operator("+"));
    
    cout << input2 << " = " << Eval(input2) << endl;
};

