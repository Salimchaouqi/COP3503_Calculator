/* 
 * File:   Expression.cpp
 * Author: max
 * 
 * Created on March 21, 2014, 6:15 AM
 */

#include "Expression.h"

Expression::Expression() {

}

Expression::Expression(const Expression& orig) {
}

Expression::~Expression() {
}

Expression::Expression(Number* number) {

    vector<Number*> element; //creates a new space in the addition array for the new element
    element.push_back(number);



    addedNumbers.push_back(element);

}

bool Expression::isConstant() {
    return false; 
}

bool Expression::isRational() {
    return false; 
}

void Expression::add(Number* number) {
    if (number->isRational()) {
        bool couldAdd = false; //represents if we can add the number with our current elements.

        //if the number we are adding is rational, we need to check if there
        //is another lonesome rational number it can be added to.
        for (int a = 0; a < addedNumbers.size(); a++) {
            if (addedNumbers[a].size() == 1 && addedNumbers[a][0]->isRational()) {
                //if there is only one element in this "addition" element, and that element is rational, add to it.
                RationalNumber* rationalElement = ((RationalNumber*) addedNumbers[a][0]);
                rationalElement->add((RationalNumber*) number);
                couldAdd = true;
            }
        }
        if (couldAdd == false) { //if I could not add to an existing rat numb, lets just add a new element.
            vector<Number*> addition; //create a new multiplication of numbers
            addition.push_back(number); //add our number to it.
            addedNumbers.push_back(addition); //add our new vector to the addition vector
        }
    } else {
        vector<Number*> element;
        element.push_back(number);
        addedNumbers.push_back(element);
    }



}

/*
 * Overloaded Methods!
 */

bool Expression::mult(Number* number) {

    if (number->isRational()) { //if the number is just a number or fraction...

        //for each of the addition objects, we need to check if there is already a rational number we can multiply by.
        //If there is not, we simply add one.
        bool containsRational = false;
        for (int a = 0; a < addedNumbers.size(); a++) {
            containsRational = false;

            for (int b = 0; b < addedNumbers[a].size(); b++) {
                if (addedNumbers[a][b]->isRational()) {
                    containsRational = true; //make sure we keep track of the fact that this particular addition entity already has a rational
      
        
                    RationalNumber* tempRat = (RationalNumber*)addedNumbers[a][b]; 
                    tempRat->mult(number);
                }
            }
            if (containsRational == false) {
                //if there was not a rational number to multiply by in this instance
                //we must add one ourselves.
                RationalNumber* rationalInput = (RationalNumber*) number;
                Number* newRational = new RationalNumber(rationalInput->getA(), rationalInput->getB()); //creates a new rational number
                addedNumbers[a].push_back(newRational);
            }

        }
    }
    /* 
     * Need to implement what to do if number is NOT a rational number!
     */


}

string Expression::getRep() {

    string output;
    ostringstream convert;

    for (int a = 1; a < addedNumbers.size(); a++) {
        for (int b = 0; b < addedNumbers[a].size(); b++) {
            convert << addedNumbers[a][b]->getRep();

            if (b != (addedNumbers[a].size() - 1)) //if this is the last element, do not print out a multiplication sign.
                convert << "*";
        }

        if (a != (addedNumbers.size() - 1)) //if this is the last element, do not print out a plus sign.
            convert << " + ";

    }
    output = convert.str();
    return output;
}

double Expression::getEstimation() {
    double est = 0.0;
    /*
     * TODO!!! IMPLEMENT METHOD!
     */
    return est;
}
