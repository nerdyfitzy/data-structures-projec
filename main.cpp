#include "BigInt.h"
#include <iostream>

int main() {
    std::cout << "here" << std::endl;

    ds::BigInt b("1123");
    ds::BigInt a("4545");
    a.print();
    b.print();
    ds::BigInt c;
    c = a - b;

    
    c.print();
    return 0;
}