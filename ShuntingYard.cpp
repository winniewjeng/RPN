
#include "ShuntingYard.hpp"

// convert user input string to token and then store queue
Queue<Token*> toToken(string expression) {
    string num_str;
    string optr_str; // operator string
    Queue<Token*> infix;
    
    for (int i = 0; i < expression.size(); i++) {
        // if the element in string is a digit, get the whole number and push it to Queue
        if (isdigit(expression[i]) || expression[i] == '.') {
            //form operand
            while (isdigit(expression[i]) || expression[i] == '.') {
                num_str += expression[i];
                i++;
            }
            double number = stod(num_str);
            infix.push(new Operand(number));
            // reset the num_str for clean reading of the next number
            num_str="";
        }
        
        // if the element in string is an operator, get the operator and push it to Queue
        if (!isdigit(expression[i]) && !isalpha(expression[i]) && expression[i] != ' ') {
            optr_str += expression[i];
            infix.push(new Operator(optr_str));
            // reset the optr_str for clean reading of the next operator
            optr_str = "";
        }
        
        // if the item in string is a trig, get the whole trig and push it to Queue
        // note that in the queue, trig tends to leave out an open paraenthesis
        if (isalpha(expression[i])) {
            while(isalpha(expression[i])) {
                optr_str += expression[i];
                i++;
            }
            infix.push(new Operator(optr_str));
            // reset the optr_str for clean reading of the next operator
            optr_str = "";
        }
        
    }
    return infix;
};

// turn the infix to postfix
Queue<Token*> toPostFix(Queue<Token*> infix) {
    // get a postfix queue
    Queue<Token*> postfix;
    // get an operator stack
    Stack<Operator*> optr;
    
    while (!infix.empty()) {
        //pop infix queue one item at a time
        Token* item = infix.pop();
        //        cout << "infix.pop() item is ";
        // if item is a number-->push item into the postfix queue
        if (item->get_type() == 0) {
            //            cout << item << " 0" << endl;
            postfix.push(item);
        }
        // if item is not a number-->check for precedence before action
        else {
            // typecast item from token to operator
            Operator* optr_item = static_cast<Operator*>(item);
            // if optr stack is empty, push optr_item straight in
            if (optr.empty()) {
                // cout << item << " 1" << endl;
                // if stack is empty-->push optr_item into the stack
                optr.push(optr_item);
                // cout << "optr stack is " << optr << endl;
                // cout << "postfix queue is " << postfix << endl;
            }
            // if optr stack is not empty, check for paranthesis and then general precedence
            else {
                // cout << item << " 2" << endl;
                // if optr_item (popped from infix queue) is a closed paranthesis,
                if (optr_item->get_symb() == ")" ) {
                    // then pop the stack & store each item in the postfix queue until finding the open parenthesis
                    while (optr.top()->get_symb() != "(" && !optr.empty()) {
                        //pop the stack and store them to postfix queue
                        postfix.push(optr.pop());
                    }
                    // then finally, pop the open parenthesis
                    optr.pop();
                }
                // if optr_item (popped from infix queue) is stacked on top of another operator with higher order of precedence
                else if (optr_item->has_precedence(optr.top())) {
                    // then pop stack & push the popped into postfix queue
                    postfix.push(optr.pop());
                    // and then push optr_item into optr stack
                    optr.push(optr_item);
                }
                // if optr_item is not a closed parenthesis or has no higher precedence, just push it into the optr stack
                else {
                    optr.push(optr_item);
                }
                // cout << "optr stack is " << optr << endl;
                // cout << "postfix queue is " << postfix << endl;
            }
        }
        
        // if infix queue has become empty, push everything in the optr stack into postfix queue
        if (infix.empty()) {
            while(!optr.empty()) {
                postfix.push(optr.pop());
            }
        }
    }
    
    return postfix;
};
