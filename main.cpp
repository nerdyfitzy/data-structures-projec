#include "BigInt.h"
#include <iostream>

int main() {
    std::cout << "here" << std::endl;

    ds::BigInt a("2588");
    ds::BigInt b("1120");
    a.print();
    b.print();
    ds::BigInt c;
    c = a + b;

    
    c.print();
    return 0;
}