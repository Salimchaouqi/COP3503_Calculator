/* 
 * File:   Number.cpp
 * Author: max
 * 
 * Created on March 21, 2014, 6:16 AM
 */

#include "Number.h"

/* 
 * ==================Number=======================
 */

/* 
 * ==================CONSTANT=======================
 */

Constant::Constant(string symbol, double value) { //sets the isRational value to false.



    this->value = value;
    this->symbol = symbol;


}

bool Constant::isConstant() {
    return true; ///....it is a constant.
}

bool Constant::isRational() {
    return false; //for our purposes, constants are never treated as rational.
}

string Constant::getRep() { //returns the symbolic representation of the number.
    string output;
    ostringstream convert;

    convert << "(" << symbol << ")";

    output = convert.str();

    return output;
}

double Constant::getEstimation() {
    return value;
}

bool Constant::mult(Number* number) { //you cannot multiply a constant. You must add a RationalNumber number to the appropriate vector instead.
    return false;
}

/* 
 * ==================INTEGER=======================
 */

RationalNumber::RationalNumber(int value) {

    a = value;
    b = 1; // (because this is not a fraction, we just make the bottom 1.)

}

RationalNumber::RationalNumber(int a, int b) {


    this->a = a;
    this->b = b;
}

bool RationalNumber::isConstant() {
    return false;
}

bool RationalNumber::isRational() {
    return true;
}

string RationalNumber::getRep() { //simply outputs a nice string of the fraction or number
    string output;
    ostringstream convert;

    if (b > 1) //if the number is a fraction, print out fraction form.
        convert << "(" << a << "/" << b << ")";
    else //print out regular number form.
        convert << a;

    output = convert.str();

    return output;
}

double RationalNumber::getEstimation() {
    return (double) a / (double) b;
}

bool RationalNumber::mult(RationalNumber* number) {

    //multiply the fraction...
    a *= number->getA();
    b *= number->getB();

    //simplify the fraction (if possible)
    simplify();

    //success!
    return true; //because it is possible to mult these two.
}

bool RationalNumber::mult(Number* number) { //redirects various different types of numbers to the appropriate method.

    if (number->isRational()) {
        RationalNumber* tempRational = (RationalNumber*) number;


        return mult(tempRational);
    }
    //TODO IMPLEMENT
    return false;
}

bool RationalNumber::add(Number* number) {
    if (number->isRational()) {
        RationalNumber* rationalNumber = ((RationalNumber*) number);
        int numberA = rationalNumber->getA();
        int numberB = rationalNumber->getB();

        //lets create a common denominator the easiest possible way.

        //first we start by multiplying the base of the number original fraction by the base of
        //the fraction that wants to be added. 
        numberA *= b;
        numberB *= b;

        //then vice-versa for the other fraction
        a *= rationalNumber->getB();
        b *= rationalNumber->getB();

        //now we have a common denominator! we can add the tops with no issues.
        a += numberA;

        //and we can then simply it back up!
        simplify();

        return true;
    } else return false; //cannot add irrational number

}

//private methods

void RationalNumber::simplify() {
    //if the number is a fraction...

    //find the lowest number (a or b)

    //set it equal to the max value we can divide our numbers by.

    //start dividing at two, trying to divide both by the value

    //if %(value) == 0 for both numbers of a particular value, try to divide
    //by that number again. 

    //keep going until you reach max.

    cout << "simplify (NOT) running now." << endl;
    
//    if (a > b) //if a is greater than b, b is the lowest number, and thus, the max value.
//        simplifyHelper(b, 2);
//    else//if(b > a) opposite of above.
//        simplifyHelper(a, 2);


}

void RationalNumber::simplifyHelper(int maxValue, int currentValue) {
    
    //in other words, if they both divide evenly into the value, actually divide them and keep going.
    if (a % currentValue == 0 && b % currentValue == 0) {
       
        a /= currentValue;
        b /= currentValue;

        //going to save some computing time by rechecking what our max value is and calling the function again.
        if (a > b)
            simplifyHelper(b, currentValue);
        else
            simplifyHelper(a, currentValue);
    }
    else if(currentValue < maxValue) {//if the numbers did not divide evenly into both, keep increasing current value until we reach max value.
        simplifyHelper(maxValue, ++currentValue);
    }

}

int RationalNumber::getA() {
    return a;
}

int RationalNumber::getB() {
    return b;
}


