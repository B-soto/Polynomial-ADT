//
//  main.cpp
//  BryceSotoADT
//
//  Created by bryce soto on 3/7/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

int main() {
    int size, size2;
    
    cout << "Hello! \nHow many terms would you like in your Polynomial:";
    cin >> size;
    
    while (size< 1){
        cout << "Error, must have at least 1 term in oyur polynomial!\nHow many terms would you like in your polynomial";
    }
    polynomial p1(size);
    
    // test degree function
    int degree = p1.degree(size);
    cout << "\nValue of the largest degree:"<< degree;
    
    //test getCoeff function
    int user_coeff;
    cout << "\nEnter the power of a term to see it's coefficient:";
    cin >>user_coeff;
    int wanted_co = p1.coeff(user_coeff, size);
    cout << "\nvalue of the coefficient:" << wanted_co;
    
    //test changing the coeff of a specific term
    int oldCo, newCo;
    cout << "\n\nChange the coeficeint of a term! \nEnter the power of a term whom's coefficient you would like to change:";
    cin >>oldCo;
    cout << "Desired new Coefficient value:" ;
    cin >> newCo;
    p1.changeCoefficient(newCo, oldCo, size);
    
    //test the multiply function
    int factor;
    cout << "\n\nBy what factor would you like to multiply your polynomial by:";
    cin>> factor;
    p1.multiply(factor, size);
    
    //test the overloaded negation function
    cout << "The Negatited polynomial is:\n\t";
    p1.operator-();
    
    //cout <<p1;
    
    //test the overloaded divide function
    cout << "\nBy what factor would you like to divide your polynomial by:";
    int dfactor;
    cin >>dfactor;
    p1.operator/(dfactor);
    
    //test the addition function
    cout << "~~ADD TOGETHER TWO DIFFERENT POLYNOMIALS~~~" << endl;
    cout<< "How many terms would you like in your 2nd polynomial:";
    cin >> size2;
    polynomial p2(size2);
    cout << "\n\nYour polynomials added together is:";
    polynomial p3 = p1+p2;
    
    //test the subtraction operator
    cout << "\n\nYour polynomials subtracted is:";
    polynomial p4 = p1-p2;
    
    
    return 0;
}
