#include <iostream>
#include "QFun.h"

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    QFun fun( a, b, c );
    fun.print();
    return 0;
}