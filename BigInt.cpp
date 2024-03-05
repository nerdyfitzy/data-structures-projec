#include <iostream>
#include <string>
#include "AList.h"
#include "BigInt.h"

namespace ds {
    int* fullAdd(int a, int b, int c = 0, bool last = false) {
        int sum = a + b + c;
        int ones = !last ? sum % 10 : sum;
        int carry = sum >= 10 ? sum / 10 : 0;

        int * r = new int[2];

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
        // std::cout << "from " << a << b << c << "ones " << diff << std::endl;
        // std::cout << "carry " << carry << std::endl;
        r[0] = diff;
        r[1] = carry;

        return r;
    }
    void BigInt::output() {
        for(int i = 0; i < length; i++) {
            std::cout << getDigit(i);
        }
        std::cout << std::endl;
    }

    BigInt operator+(BigInt  &a, BigInt  &b) {
        if(a.size() == 1 && a.getDigit(0) == 0) return b;
        if(b.size() == 1 && b.getDigit(0) == 0) return a;
        
        int longest = a.size() > b.size() ? a.size() : b.size();
        int shortest =  a.size() < b.size() ? a.size() : b.size();
        std::string fullSum;
        longest--;
        shortest--;
        int * r = new int[2];
        r[1] = 0;
        while(longest >= 0) {
            //a is meant to be the longer num, conditionals to make sure
            int aDigit = a > b ? a.getDigit(longest) : b.getDigit(longest),
                bDigit = shortest >= 0 ? a > b ? b.getDigit(shortest) : a.getDigit(shortest) : 0;
            
            //add them and do not use a carry if its the last loop
            r = fullAdd(aDigit, bDigit, r[1], longest == 0 ? true : false);
            // std::cout << i << " is " << r[0] << std::endl;
            fullSum.insert(0, std::to_string(r[0]));

            longest--;
            shortest--;

            // std::cout << "----------" << std::endl;
        }

        delete [] r;
        return BigInt(fullSum);
    }

    //3249870980356
    //   3294057890
    //           46

    BigInt operator-(BigInt &a, BigInt &b) {
        if(a.size() == 1 && a.getDigit(0) == 0) return b;
        if(b.size() == 1 && b.getDigit(0) == 0) return a;


        int longest = a.size() > b.size() ? a.size() : b.size(),
            shortest = a.size() < b.size() ? a.size() : b.size();

        
        std::string fullDiff;
        int * r = new int[2];
        r[1] = 0;
        longest--;
        shortest--;
        int diff = longest - shortest;
        while(longest >= 0) {
            //a is the longer, b is shorter
            int aDigit = a > b ? a.getDigit(longest) : b.getDigit(longest),
                bDigit = shortest >= 0 ? a > b ? b.getDigit(shortest) : a.getDigit(shortest) : 0;

            //checks if we should use leading zeroes for the shorter number
            if(longest == diff) {
                int n = aDigit - bDigit;
                if(n < 0) {
                    n += (b.getDigit(longest - 1) * 10);
                }

                r[0] = n;
            }else {
                r = fullSub(aDigit, bDigit, r[1]);
            }
            
            // std::cout << "longest" << longest << " shortest " << shortest << std::endl;
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
        c = a + b;
    }
    void BigInt::subtract(BigInt &a, BigInt &b, BigInt &c) {
        c = a - b;
    }
}