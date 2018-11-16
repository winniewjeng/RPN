
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
//#include "LinkedList.hpp"
#include "Queue.hpp"
#include <iostream>
#include "SimpleList.hpp"
#include "Stack.hpp"
#include "SimpleList.hpp"

double Eval(Queue<Token*> postfix);

using namespace std;

int main(int argc, const char * argv[]) {
//
//    Queue<int> q;
//    q.push(4);
//    cout << q.pop() << endl;
    
    Queue<Token*> input;

    input.push(new Operand(5));
    input.push(new Operand(4));
    input.push(new Operator('+'));
    
    cout << input << endl;
    
    return 0;
}

double Eval(Queue<Token*> postfix) {

    Stack<Token*> s;
    
//    while (!postfix.empty() && s.get_size() == 1) {
//        p = postfix.pop();
//        
////        if (p.tokenType() == 0) {
////            
////        } else {
////            
////        }
//        Token* item = postfix.pop();
////        if ()
//        s.push(item);
//        
//    }
    
    return 4;
};
