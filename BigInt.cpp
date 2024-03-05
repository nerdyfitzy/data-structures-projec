#include <iostream>
#include <string>
#include "SLList.h"
#include "BigInt.h"

namespace ds {
    int* fullAdd(int a, int b, int c = 0, bool last = false) {
        int sum = a + b + c;
        int ones = !last ? sum % 10 : sum;
        int carry = sum >= 10 ? sum / 10 : 0;

        int * r = new int[2];
        // std::cout << "from " << a << b << c << "ones " << ones << std::endl;
        // std::cout << "carry " << carry << std::endl;
        r[0] = ones;
        r[1] = carry;
        return r;
    }
    int* fullSub(int a, int b, int c = 0) {
        int diff = a - b + c,
            carry = 0;
        if(diff < 0) {
            diff += 10;
            carry = -1;
        }
        int * r = new int[2];
        std::cout << "from " << a << b << c << "ones " << diff << std::endl;
        std::cout << "carry " << carry << std::endl;
        r[0] = diff;
        r[1] = carry;

        return r;
    }
    void BigInt::output() {
        for(int i = 0; i < this->length; i++) {
            std::cout << getDigit(i);
        }
        std::cout << std::endl;
    }

    BigInt operator+(BigInt  &a, BigInt  &b) {
        if(a.size() == 1 && a.getDigit(0) == 0) return b;
        if(b.size() == 1 && b.getDigit(0) == 0) return a;
        
        //find sizes to loop through for each number
        int longest = a.size() > b.size() ? a.size() : b.size();
        int shortest =  a.size() < b.size() ? a.size() : b.size();
        std::string fullSum;
        //adjust to be indices not sizes
        longest--;
        shortest--;
        //making an array for sum and carry
        int * r = new int[2];
        r[1] = 0;
        while(longest >= 0) {
            //get each digit, a should be the longer num and b the shorter
            int aDigit = a > b ? a.getDigit(longest) : b.getDigit(longest),
                bDigit = shortest >= 0 ? a > b ? b.getDigit(shortest) : a.getDigit(shortest) : 0;
            
            //add them, if its the last loop then do not use a carry
            r = fullAdd(aDigit, bDigit, r[1], longest == 0 ? true : false);

            //put the sum in the sum string
            fullSum.insert(0, std::to_string(r[0]));

            longest--;
            shortest--;

            // std::cout << "----------" << std::endl;
        }

        //finalization
        delete [] r;
        std::cout << "fsum: ";
        BigInt fsum(fullSum);
        fsum.output();
        return fsum;
    }


    BigInt operator-(BigInt &a, BigInt &b) {
        if(a.size() == 1 && a.getDigit(0) == 0) return b;
        if(b.size() == 1 && b.getDigit(0) == 0) return a;

        //find shorter/longer sizes
        int longest = a.size() > b.size() ? a.size() : b.size(),
            shortest = a.size() < b.size() ? a.size() : b.size();

        
        std::string fullDiff;
        int * r = new int[2];
        r[1] = 0;
        //adjust for indices
        longest--;
        shortest--;
        //for leading zeroes
        int diff = longest - shortest;
        while(longest >= 0) {
            //a should be the longer number and b the shorter
            int aDigit = a > b ? a.getDigit(longest) : b.getDigit(longest),
                bDigit = shortest >= 0 ? a > b ? b.getDigit(shortest) : a.getDigit(shortest) : 0;

            //recognizes where there should be leading zeroes
            if(longest == diff) {
                int n = aDigit - bDigit;
                if(n < 0) {
                    n += (b.getDigit(longest - 1) * 10);
                }

                r[0] = n;
            }else {
                r = fullSub(aDigit, bDigit, r[1]);
            }
            
            //insert into the diff string
            fullDiff.insert(0, std::to_string(r[0]));

            shortest--;
            longest--;
        }
        // for(int i = longest; i >= diff; i--) {
        //     int aDigit = a > b ? a.getDigit(i) : b.getDigit(i),
        //         bDigit = a > b ? b.getDigit(i) : a.getDigit(i);

        //     if(i == diff) {
        //         int n = aDigit - bDigit;
        //         if(n < 0) {
        //             n += (b.getDigit(i - 1) * 10);
        //         }

        //         r[0] = n;
        //     }else {
        //         r = fullSub(aDigit, bDigit, r[1]);
        //     }
            
        //     std::cout << i << " is " << r[0] << std::endl;
        //     fullDiff.insert(0, std::to_string(r[0]));
        // }

        delete [] r;
        return BigInt(fullDiff);
    }

    bool operator>(BigInt &a, BigInt &b) {
        if(a.size() > b.size()) return true;
        else if(b.size() > a.size()) return false;

        for(int i = 0; i < a.size() - 1; i++) {
            if(a.getDigit(i) > b.getDigit(i)) return true;
            else if(b.getDigit(i) > a.getDigit(i)) return false;
        }

        return false;
    }

    void BigInt::add(BigInt &a, BigInt &b, BigInt &c) {
        BigInt t;
        t = a + b;
        
        for(int i = 0; i < t.size(); i++) {
            c.addLast(t.getDigit(i));
        }
    }
    void BigInt::subtract(BigInt &a, BigInt &b, BigInt &c) {
        BigInt t;
        t = a + b;
        
        for(int i = 0; i < t.size(); i++) {
            c.addLast(t.getDigit(i));
        }
    }
}