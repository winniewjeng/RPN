

#ifndef ShuntingYard_hpp
#define ShuntingYard_hpp

#include "SimpleList.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"

//parse the user-input string into tokens and store them in queue
Queue<Token*> toToken(string expression);
//convert the infix queue to a post-fix queue using Shunting-Yard algorithm
Queue<Token*> toPostFix(Queue<Token*> infix);

#endif /* ShuntingYard_hpp */
