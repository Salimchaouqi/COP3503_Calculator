/* 
 * File:   Number.h
 * Author: max
 *
 * Created on March 21, 2014, 7:04 AM
 */

#ifndef NUMBER_H
#define	NUMBER_H

using namespace std;
#include <iostream>
#include <sstream>

class Number {
    
public:
    
    //methods to override
    virtual string getRep() = 0;
    virtual double getEstimation() = 0; //returns estimated (or exact if rational) value.

    
    virtual bool mult(Number* number) = 0; //returns true if successful, false if not applicable to the number(i.e. constant)
    
    virtual bool isRational() = 0; //I make all of the number subclasses determine weather they are rational or not.
    virtual bool isConstant() = 0; 
    
    
};


class Constant : public Number {
public:
    
    Constant(string symbol, double value);
    void add(Number* number);
    
    //Methods that have been overriden
    string getRep();
    double getEstimation();
    
    bool mult(Number* number);
    
    bool isRational();
    bool isConstant();
    
    
private:
    double value;
    string symbol;
    
};

class RationalNumber : public Number {
    
public:
    RationalNumber(int value); //for creating just an easy integer
    
    RationalNumber(int a, int b); //for creating a fraction
    
    int getA(); //returns each fraction part individually.
    int getB();
    
    //methods to override
    string getRep();
    double getEstimation();
    
    bool mult(Number* number);//sorts into the other private methods, otherwise returns false.
    bool add(Number* number); //can only add rational numbers. Returns false otherwise.
    
    bool isConstant();
    bool isRational();
    
private:
    int a; //these two variables represent the fraction, since any rational number can be represented
    int b; //as two integers, a/b
    
    bool mult(RationalNumber* number);
    
    void simplify(); //simplifies the factional expression to its lowest terms.
    
    void simplifyHelper(int maxValue, int currentValue);
    
protected:
    
};




#endif	/* NUMBER_H */

