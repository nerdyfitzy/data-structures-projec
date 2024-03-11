#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BigInt.h"
#include "BigInt.cpp"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
  ds::BigInt a("43253265987902374");
  ds::BigInt b("43253265987902374");

  // a.output(); //this should display a's value: 1234567890123

  ds::BigInt r;
  // r = a + b;
  ds::BigInt::subtract(a,b,r);
  std::cout << "outputting ";
  r.output();  //This should display 1236135780246

  // ds::BigInt r2;
  // ds::BigInt::subtract (a,b,r2);
  
  // r2.output (); //This should display 123000000000

  
 
}
