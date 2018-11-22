#include "SimpleList.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"

//evaluate the rpn expression
double Eval(Queue<Token*> postfix);
//parse the user-input string into tokens and store them in queue
Queue<Token*> toToken(string expression);

using namespace std;

int main(int argc, const char * argv[]) {
    
    //    cout << "hello world" << endl;
    //    Queue<int> q;
    //    q.push(4);
    //    cout << q.pop() << endl;
    
    string infix;
    cout << "Enter the operation: ";
    cin >> infix;
    
    // parse string into chars and store them inside a char queue
    Queue<char> infixCharQ;
    string num_str;
    string trig_str;
    Queue<Token*> input;
    
    for (int i = 0; i < infix.size(); i++) {
        
        if (isdigit(infix[i]) || infix[i] == '.') {
            //form operand
            while (isdigit(infix[i]) || infix[i] == '.') {
                num_str+=infix[i];
                i++;
            }
//            cout << num_str << "\n";
            double number = stod(num_str);
            input.push(new Operand(number));
            num_str="";
        }
        
//        cout << infix[i] << endl;
        trig_str+= infix[i];
        input.push(new Operator(trig_str));
        trig_str = "";
        //account for sine and cosine and tangent in this funciton too
//        if (!isdigit(infix[i]) && infix[i] != '.') {
//            trig_str = infix[i];
//            while (!isdigit(infix[i]) && infix[i] != '.') {
//                trig_str+=infix[i];
//                i++;
//            }
//            cout << trig_str << "\n";
//            input.push(new Operator(trig_str));
//            trig_str="";
//        }
        
//        else {
//            cout << "her";
//            cout << infix[i] << " ";
//        }
    }
    
    cout << endl;
    cout << input << endl;
    //    cout << infixCharQ << endl;
    
    
    // parse the char queue, turn the numbers into numbers, and store them all inside a token queue
    //    while( !infixCharQ.empty() ) {
    //        cout << infixCharQ.top() << " ";
    //
    //        infixCharQ.pop();
    //        if ( isdigit(infixCharQ.top()) || infixCharQ.top() == '.' ) {
    //            //cout << infixCharQ.top() << " ";
    //            num_str += infixCharQ.top();
    //
    //        } else {
    //            cout << num_str << endl;
    //            //convert num_string to double
    //            double number = stod(num_str);
    //            //create a new number token and push it to the token queue input
    //            input.push(new Operand(number));
    //            //resetting num_string
    //            num_str = "";
    //            //cout << " | " << infixCharQ.top() << " | ";
    //            //push the top of the infixCharQueue also to the queue
    //            input.push(new Operator(infixCharQ.top()));
    //        }
    //
    //        infixCharQ.pop();
    
    //    }
    //    cout << input << endl;
    
    
    //    Queue<Token*> input;
    //
    //    input.push(new Operand(4));
    //    input.push(new Operand(2));
    //    input.push(new Operator('+'));
    //    input.push(new Operand(5));
    //    input.push(new Operator('*'));
    //
    //    cout << "Evaluate: " << endl;
    //    cout << input << " = " << Eval(input) << endl;
    //
    //    Queue<Token*> input2;
    //
    //    input2.push(new Operand(8));
    //    input2.push(new Operand(3));
    //    input2.push(new Operator('-'));
    //    input2.push(new Operand(5));
    //    input2.push(new Operator('+'));
    //    input2.push(new Operand(5));
    //    input2.push(new Operator('-'));
    //
    //    cout << input2 << " = " << Eval(input2) << endl;
    
    return 0;
    
    //    for (int i = 0; i < infix.size(); i++) {
    //        //while the element in string is digit or decimal, get the whole number before tokenizing
    //        double number_bank = 0;
    //
    //        while (isdigit(infix[i]) || infix[i] == '.') {
    //            // if a decimal is detected
    //            if (infix[i] == '.') {
    //                if (number_bank == 0 && i == 0) {
    //                    number_bank = 1;
    //                } else {
    //                    number_bank /= 10; }
    //                cout << "number bank is "<< number_bank << endl;
    //            }
    //            // if a digit is detected
    //            else {
    //                cout << "i is "<< i << endl;
    //                if(i == 0) {
    //                    //if the digit is at the start of the string, it's a single digit
    //                    number_bank = ((double)infix[i] - 48);
    //
    //                    cout << "is ! " << number_bank << endl;
    //                } else if ((isdigit(infix[i-1])) || infix[i-1] == '.' ) {
    //                    // if digit is trailing after another digit or a decimal, append it to the other number
    //
    //                    if (number_bank < 1) {
    //                        cout << "numbre bank <1 before is "<< number_bank << endl;
    //                        number_bank = number_bank * 10 + ( (double)infix[i] - 48) / 10;
    //                        cout << "numbre bank <1 after is "<< number_bank << endl;
    //                    }
    //                    else {
    //                        cout << "numbre bank >=1 after is "<< number_bank << endl;
    //                        number_bank = number_bank * 10 + (double)infix[i] - 48;
    //                        cout << "numbre bank >=1 after is "<< number_bank << endl;
    //                    }
    //                    cout << "numbre bank ais "<< number_bank << endl;
    //                    cout << "ehh what "<< (double)infix[i] - 48 << endl;
    ////                    cout << "&" << number_bank << endl;
    //                } else {
    //                    // if digit is not after another digit, it's a single digit
    //                    number_bank = (double)infix[i] - 48;
    //                }
    //            }
    //            //traverse down the string
    //            i++;
    //        }
    //        cout << number_bank << endl;
    
    
    //        int num_order = 1; // multiply tenfold each time a digit is followed by another digit
    //        if(isdigit(infix[i])) {
    //            double number = double(infix[i]);
    //        } else if ()
    
    //    }
    
    //store the user input inside a Queue
    //    Queue<Token*> infixQ = toToken(infix);
    //    cout << infixQ;
    /*
     attack plan:
     //get an infix order string
     //parse the string into token and store it in queue
     //perform operations:
     //get a populated queue of infix tokens
     
     //get an emptry queue of postfix tokens
     //get a stack of operator tokens
     //if it's a number, add it to the output
     //if it's an operator, check precedence
     //if precedence is correct, push it to the stack
     //if not, add it pop a stack to the postfix queue and push operator to stack
     //keep doing it until stack operator tokens has no more element
     */
}

//Queue<Token*> toToken(string expression) {
//    //get an infixQ
//    Queue<Token*> infixQ;
//    //loop through user-input infix expression string
//    for (int i = 0; i <expression.size(); i++) {
//        // char element of the string is an operand (a number)
//        if (isdigit(expression[i])) {
//            cout << expression[i] << endl;
//            //convert the char into double
//            double digit = isdigit(expression[i]);
//            cout << digit << endl;;
//            //push the element into the infix Queue
//            infixQ.push(new Operand(digit));
//        }
//        // char element of the string is an operator
//        else {
//            //push the element into the infix Queue
//            infixQ.push(new Operator(expression[i]));
//        }
//        //        cout << infixQ << endl;
//    }
//    return infixQ;
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

