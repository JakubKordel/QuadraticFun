//
// Created by Jakub Kordel on 01.03.19.
//

#include "QFun.h"

QFun::QFun( double a, double b, double c ){
    parA = a;
    parB = b;
    parC = c;
    firstZero = nullptr;
    findZeros();
}

QFun::~QFun(){
    clearZeros();
}

void QFun::setParameter( Parameter parameter, double value ){
    if ( parameter == A)
        parA = value;
    if ( parameter == B)
        parB = value;
    if ( parameter == C)
        parC = value;
    findZeros();
}

void QFun::findZeros() {
    double delta;
    clearZeros();
    if ( parA == 0 ){
        {
            if ( parB == 0 ) {
                type = CONSTANS;
                if ( parC == 0 ) {
                    firstZero = new Zero;
                    firstZero ->value = 0;
                    firstZero ->next = nullptr;
                }
            }
            else{
                firstZero = new Zero;
                firstZero ->value = -parC/parB;
                type = LINEAR;
            }
        }
    }
    else{
        type = QUADRATIC;
        delta = pow( parB, 2 ) - 4*parA*parC;
        if ( delta == 0 ){
            firstZero = new Zero;
            firstZero ->value = -parB/(2*parA);
            firstZero ->next = nullptr;
        }
        if ( delta > 0 )
        {
            Zero * secondZero;
            secondZero = new Zero;
            secondZero ->value = (-parB+pow( delta, 0.5 ) )/(2*parA);
            secondZero ->next = nullptr;
            firstZero = new Zero;
            firstZero ->next = secondZero;
            firstZero ->value = (-parB-pow( delta, 0.5 ) )/(2*parA);
        }
    }
}

void QFun::clearZeros() {
    Zero * del;
    while ( firstZero ){
        del = firstZero;
        firstZero = firstZero ->next;
        delete  del;
    }
}

void QFun::print() {
    if ( type == CONSTANS ) {
        std::cout << "\ny(x) = " << parC;
        std::cout << "\nFunction is constant";
    }
    if ( type == LINEAR ) {
        std::cout << "\ny(x) = " << parB << "x + " << parC;
        std::cout << "\nFunction is linear";
    }
    if ( type == QUADRATIC ){
        std::cout << "\ny(x) = " << parA << "x^2 + "<< parB << "x + " << parC;
        std::cout << "\nFunction is quadratic";
    }
    std::cout << "\nzeros: ";
    Zero * zero;
    zero = firstZero;
    while ( zero ){
        std::cout << std::fixed << std::setprecision(2) << zero ->value << "   ";
        zero = zero ->next;
    }
    std::cout << std::endl;
}
