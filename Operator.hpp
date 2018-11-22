
#ifndef Operator_hpp
#define Operator_hpp
#include <iostream>
#include "Token.hpp"

using namespace std;

class Token;

class Operator : public Token {
    
public:
    Operator(char symb): _symb(symb) {}
    void print(ostream& outs = cout) const {
        outs << _symb;
    }
    int get_type() {return 1;}
    
    double do_math(double LHS, double RHS) {
        switch(_symb) {
            case '+': return (LHS + RHS);
            case '-': return (LHS - RHS);
            case '*': return (LHS * RHS);
            case '/': return (LHS / RHS);
            default: cout << "unrecognizable operator\n";
                return -1;
        }
    }
    
    char get_symb() {return _symb;}
    
    //check order of operation over the token below you
    bool has_precedence(Operator* last, Operator* current) {
        return true;
    }
    
private:
    char _symb;
};

#endif /* Operator_hpp */
