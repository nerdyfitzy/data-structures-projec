#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <string>
#include "AList.h"
#include <iostream>


namespace ds {
    class BigInt {
        private:
            AList<int> digits; // stores the digits of the BigInt
            int length;
        public:
            BigInt(const std::string &val = "") {
                for (int j = 0; j < val.length(); j++) {
                digits.addLast(val[j] - '0');
                }

                length = digits.size();
            };
            int size() {
                return digits.size();
            }
            int getDigit(int i) {
                return i < digits.size() ? digits.get(i) : 0;
            }

            void addFirst(int i) {
                digits.addFirst(i);
            }

            void print() {
                for(int i = 0; i < length; i++) {
                    std::cout << getDigit(i);
                }
                std::cout << std::endl;
            }

            friend BigInt operator+(BigInt  &a, BigInt  &b);
            friend BigInt operator-(BigInt &a, BigInt &b);
    };


    int* fullAdd(int a, int b, int c) {
        int sum = a + b + c;
        int ones = sum % 10;
        int carry = sum >= 10 ? sum / 10 : 0;

        int * r = new int[2];
        // std::cout << "from " << a << b << c << "ones " << ones << std::endl;
        // std::cout << "carry " << carry << std::endl;
        r[0] = ones;
        r[1] = carry;
        return r;
    }


    BigInt operator+(BigInt  &a, BigInt  &b) {
        int longest = a.size() > b.size() ? a.size() : b.size();
        std::string fullSum;
        longest--;
        int * r;
        for(int i = longest; i >= 0; i--) {
            int aDigit = a.getDigit(i),
                bDigit = b.getDigit(i);
            
            if(i == longest) {
                r = fullAdd(aDigit, bDigit, 0);
            }else {
                r = fullAdd(aDigit, bDigit, r[1]);
            }
            // std::cout << i << " is " << r[0] << std::endl;
            fullSum.insert(0, std::to_string(r[0]));
            
        }

        return BigInt(fullSum);
    }

    BigInt operator-(BigInt &a, BigInt &b) {
        
    }
}

#endif __BIGINT_H__