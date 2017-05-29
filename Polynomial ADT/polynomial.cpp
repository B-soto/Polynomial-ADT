//
//  Polynomial.cpp
//  BryceSotoADT
//
//  Created by bryce soto on 3/7/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#include <string>
#include <iostream>
#include "Polynomial.h"
#include <stdio.h>

//default construcor
polynomial::polynomial(): coefficient{0}, power{0}{
}

// consructor
polynomial::polynomial(int size){
    getPolynomial(size);
}

void polynomial::getPolynomial(int size){
    for (int i = 0; i < size; i++){
        coefficient[i]=0;
        power[i]=0;
    }
    int i=0;
    while (i <size){
        if (i == 0){ //first term
            cout << "1st term" << endl;
            cout << "Coefficent:";
            cin >> coefficient[i];
            cout << "Power:";
            cin >> power[i];
            while( power[i] < 0){
                cout << "Error: Please enter the a positive exponet\n";
                cout << "Power:" << endl;
                cin >> power[i];
            }
        }
        if (i == 1){ //second term
            cout << "2nd term" << endl;
            cout << "Coefficent:";
            cin >> coefficient[i];
            cout << "Power:";
            cin >> power[i];
            while( power[i] < 0){
                cout << "Error: Please enter the a positive exponet\n";
                cout << "Power:" << endl;
                cin >> power[i];
            }
        }
        if (i == 2){ //third term
            cout << "3rd term" << endl;
            cout << "Coefficent:";
            cin >> coefficient[i];
            cout << "Power:";
            cin >> power[i];
            while( power[i] < 0){
                cout << "Error: Please enter the a positive exponet\n";
                cout << "Power:" << endl;
                cin >> power[i];
            }
        }
        if (i>2){ // n'th term
            cout <<(i+1) << "th term\n";
            cout << "Coefficent:";
            cin >> coefficient[i];
            cout << "Power:";
            cin >> power[i];
            while( power[i] < 0){
                cout << "Error: Please enter the a positive exponet\n";
                cout << "Power:" << endl;
                cin >> power[i];
            }
        }
        i++;
        
    }
    
    cout << "Thank you for your input, your polynomial that you entered is:";
    for (int i = 0; i < size; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    } cout << "\n";
}


int polynomial::degree(int size){
    int max=1;
    for (int i = 0; i <size ; i++){
        if (power[i] > max){
            max = power[i];
        }
    }
    return max;
}


int polynomial::coeff(int expo, int size){
    int value = 0;
    for (int i =0; i < size; i++){
        if (power[i] == expo){
            cout << "The coefficient with a power of '"<< expo << "'" << "is:" << coefficient[i];
            value = coefficient[i];
        }
    }
    return value;
}

void polynomial::changeCoefficient(int newCo, int expo, int size){
    for (int i =0; i < size; i++){
        if (power[i] == expo){
            coefficient[i] = newCo;
        }
    }
    cout << "Your new polynomial is:";
    for (int i = 0; i < size; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    } cout << "\n";
}

void polynomial::multiply(int factor, int size){
    for (int i = 0; i < size; i++){
        coefficient[i] = factor*coefficient[i];
    }
    cout << "\nYour new polynomial is:";
    for (int i = 0; i < size; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    cout << "\n";
}


polynomial polynomial::operator+(const polynomial& rhs){
    polynomial p;
    int temp;
    for (int i = 0; i < 40; i ++){
        //add like terms
        if (this->power == rhs.power){
            p.power[i] = rhs.power[i];
            p.coefficient[i] = this->coefficient[i] + rhs.coefficient[i];
        }else{
            p.power[i] = i;
            p.coefficient[i] = this->coefficient[i] + rhs.coefficient[i];
        }
    }
    for (int i = 0; i < 40; i++){
        if(p.coefficient[i] != 0){
            cout << p.coefficient[i] << "X^" << power[i];
            if (p.coefficient[i+1] == 0){
                cout << ".";
            }else if (p.coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    
    return p;
}

polynomial polynomial::operator-(const polynomial& rhs){
    polynomial p;
    
    for (int i = 0; i < 40; i ++){
        //add like terms
        if (this->power == rhs.power){
            p.power[i] = rhs.power[i];
            p.coefficient[i] = this->coefficient[i] - rhs.coefficient[i];
        }else{
            p.power[i] = i;
            p.coefficient[i] = this->coefficient[i] - rhs.coefficient[i];
        }
    }
    for (int i = 0; i < 40; i++){
        if(p.coefficient[i] != 0){
            cout << p.coefficient[i] << "X^" << power[i];
            if (p.coefficient[i+1] == 0){
                cout << ".";
            }else if (p.coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    
    return p;
}




polynomial polynomial::operator-(){
    for (int i = 0; i < 40; i++){
        if(coefficient[i] != 0){
            coefficient[i] = coefficient[i]*-1;
        }
    }
    cout << "\nYour new polynomial is:";
    for (int i = 0; i < 40; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    cout << "\n";
    return *this;
}



polynomial polynomial::operator/(int dfactor){
    for (int i = 0; i < 40; i++){
        if(coefficient[i] != 0){
            coefficient[i] = coefficient[i]/dfactor;
        }
    }
    cout << "\nYour new polynomial is:";
    for (int i = 0; i < 40; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    cout << "\n";
    return *this;
}

ostream& operator<<(ostream& out, const polynomial& rhs){
    //rhs.printpoly();
    out << "\n\nMy Polynomial #: ";
    rhs.printpoly();
    /*
     for (int i = 0; i < 40; i++){
     if(rhs.coefficient[i] != 0){
     cout << coefficient[i] << "X^" << power[i];
     if (coefficient[i+1] == 0){
     cout << ".";
     }else if (coefficient[i+1] > 0) {
     cout << " + ";
     }else{
     cout <<" ";
     }
     
     }
     }
     
     */
    return out;
    
}

void polynomial::printpoly()const{
    for (int i = 0; i < 40; i++){
        if(coefficient[i] != 0){
            cout << coefficient[i] << "X^" << power[i];
            if (coefficient[i+1] == 0){
                cout << ".";
            }else if (coefficient[i+1] > 0) {
                cout << " + ";
            }else{
                cout <<" ";
            }
            
        }
    }
    
}










