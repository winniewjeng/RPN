
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
    int get_type(){return 1;}
    
    double do_math(Token* RHS, Token* LHS); //{
//        static_cast<Operator*>(RHS)->
//    }
    
private:
    char _symb;
};

#endif /* Operator_hpp */
