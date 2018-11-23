
#ifndef Operator_hpp
#define Operator_hpp
#include <iostream>
#include "Token.hpp"

using namespace std;

class Token;

class Operator : public Token {
    
public:
    Operator(string symb): _symb(symb) {}
    void print(ostream& outs = cout) const {
        outs << _symb;
    }
    int get_type() {return 1;}
    
    double do_math(double LHS, double RHS) {
        if (_symb == "+") {
            return (LHS + RHS);
        } else if (_symb == "-") {
            return (LHS - RHS);
        } else if (_symb == "*") {
            return (LHS * RHS);
        } else if (_symb == "/") {
            return (LHS / RHS);
        } else {
            cout << "unrecognizable operator\n";
        }
        return -1;
    }
    
    string get_symb() {return _symb;}
    
    //check order of precedence with the next token in stack
    bool has_precedence(Operator* other) {
        if (other->_symb != "*" || other->_symb != "/") {
            return false;
        }
        return true;
    }
    
private:
    string _symb;
};

#endif /* Operator_hpp */
