#include "BigInt.h"
#include "BigInt.cpp"
#include <iostream>

int main() {
    std::cout << "here" << std::endl;

    ds::BigInt a("3245345345345903");
    ds::BigInt b("2345345");
    a.output();
    b.output();
    ds::BigInt c;
    ds::BigInt::subtract(a, b, c);

    
    c.output();
    return 0;
}