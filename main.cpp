/* 
 * File:   main.cpp
 * Author: max
 *
 * Created on March 21, 2014, 6:12 AM
 */

#include <cstdlib>
#include "Number.h"
#include "Expression.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Constant c('p', 3.14);
    
    Number* pi = new Constant("pi", 3.141592654);
    
    //cout << pi->getRep();
    
    Number* two = new RationalNumber(2);
    
    Number* oneHalf = new RationalNumber(1,2);
    
    Number* poop = new Constant("poop", 3.141592654);
    
    //cout << two->getRep() << endl;
   // cout << oneHalf->getRep() << endl;
   // cout << pi->getRep() << endl;
    
    
    Expression* exp = new Expression(pi);
    
    //exp->add(two);
    
    exp->add(oneHalf);
    
    
    exp->mult(two);
    exp->mult(two);
    exp->add(poop);
    
    exp->add(two);
    
    //exp->add(oneHalf);
   //exp->mult(oneHalf);
   
   /* 
    * Fishy stuff is going on here. Something is not working right.
    */
   
   //exp->mult(oneHalf);
   
  // exp->mult(pi);
   //exp->mult(oneHalf);
    
   cout << exp->getRep();
    
    
    
    return 0;
}


