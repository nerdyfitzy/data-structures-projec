#include "BigInt.h"
#include <iostream>

int main() {
    std::cout << "here" << std::endl;

    ds::BigInt a("99923714987642389576897657815432452134123443564352134456657878693");
    ds::BigInt b("95790763459678971263087");
    a.output();
    b.output();
    ds::BigInt c;
    c = a - b;

    
    c.output();
    return 0;
}