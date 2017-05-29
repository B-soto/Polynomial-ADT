//
//  Polynomial.h
//  BryceSotoADT
//
//  Created by bryce soto on 3/7/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

#include <string>
#include <iostream>

using namespace std;

class polynomial{
private:
    //int size;
    int coefficient[40];
    int power[40];
    
public:
    //default constructor
    polynomial();
    //constructor
    polynomial(int size);
    
    //gets user defined polynomial
    void getPolynomial(int size);
    
    //returns the value of the highest dgree
    int degree(int size);
    
    //returns the coefficient of a specified power
    int coeff(int expo, int size);
    
    //changes the coefficient of a specified power
    void changeCoefficient(int newCoefficient, int expo, int size);
    
    //negates the polynomial
    void multiply(int factor,int size);
    
    //overloads the + operator
    //adds two polynomials together
    polynomial operator+(const polynomial& rhs);
    
    
    // polynomial operator-(const polynomial& rhs);
    polynomial operator-(const polynomial& rhs);
    
    //overloads the - operator
    //negates the polynomial
    polynomial operator-();
    
    //overloads the / operator
    //divides the polynomial by a certain value
    polynomial operator/(int divide);
    
    void printpoly() const;
    
    //friend overload...prints out polynomial
    friend ostream& operator<<(ostream& out, const polynomial);
    
    
    
    
};

#endif /* Polynomial_h */
