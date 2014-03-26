/* 
 * File:   Expression.h
 * Author: max
 *
 * Created on March 21, 2014, 6:15 AM
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

//#include <iostream>
#include "Number.h"
#include <vector>

using namespace std;

/*
 * GENIUS INSIGHT! Treat the expression class like any other number! If done right, the implications could be huge!
 */
class Expression : public Number{
public:
    Expression();
    Expression(const Expression& orig);
    virtual ~Expression();
    
    Expression(Number* number);
    
    //overloaded methods!
    string getRep();
    double getEstimation();
    bool mult(Number* number); //this method will multiply everything in the Expression 
    bool isConstant();
    bool isRational();
    
    
    void add(Number* number);
    
private:
     vector< vector<Number*> > addedNumbers; //first vector is a vector of vectors that hold number Numbers.
          
     
     
    /* 
     * So here is what I want to do: I want to implement the mult method for the expression class.
     */
    
};

#endif	/* EXPRESSION_H */

