//
// Created by jakub on 01.03.19.
//

#ifndef QUADRATICFUNCTION_QFUN_H
#define QUADRATICFUNCTION_QFUN_H

#include <iostream>
#include <cmath>
#include <iomanip>

enum Parameter { A, B, C };
enum funType { CONSTANS, LINEAR, QUADRATIC };

struct Zero {
    double value;
    Zero * next;
};

class QFun {
    double parA;
    double parB;
    double parC;
    Zero *firstZero;
    funType type;
    void findZeros();
    void clearZeros();
public:
    QFun( double = 0, double = 0, double = 0 );
    ~QFun();
    void setParameter( Parameter, double );
    void print();

};


#endif //QUADRATICFUNCTION_QFUN_H
