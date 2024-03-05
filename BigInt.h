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
            friend bool operator>(BigInt &a, BigInt &b);
    };


    int* fullAdd(int a, int b, int c = 0) {
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
    int* fullSub(int a, int b, int c = 0) {
        int diff = a - b - c,
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
    //2150
    //0452

    //   8


    BigInt operator+(BigInt  &a, BigInt  &b) {
        int longest = a.size() > b.size() ? a.size() : b.size();
        std::string fullSum;
        longest--;
        int * r = new int[2];
        r[1] = 0;
        for(int i = longest; i >= 0; i--) {
            int aDigit = a.getDigit(i),
                bDigit = b.getDigit(i);
            
            r = fullAdd(aDigit, bDigit, r[1]);
            // std::cout << i << " is " << r[0] << std::endl;
            fullSum.insert(0, std::to_string(r[0]));
            
        }
        delete [] r;
        return BigInt(fullSum);
    }

    BigInt operator-(BigInt &a, BigInt &b) {
        int longest = a.size() > b.size() ? a.size() : b.size(),
            shortest = a.size() < b.size() ? a.size() : b.size();

        
        std::string fullDiff;
        int * r = new int[2];
        r[1] = 0;
        longest--;
        shortest--;
        int diff = longest - shortest;
        for(int i = longest; i >= diff; i--) {
            int aDigit = a > b ? a.getDigit(i) : b.getDigit(i),
                bDigit = a > b ? b.getDigit(i) : a.getDigit(i);

            if(i == diff) {
                int n = aDigit - bDigit;
                if(n < 0) {
                    n += (b.getDigit(i - 1) * 10);
                }

                r[0] = n;
            }else {
                r = fullSub(aDigit, bDigit, r[1]);
            }
            
            std::cout << i << " is " << r[0] << std::endl;
            fullDiff.insert(0, std::to_string(r[0]));
        }

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
}

#endif __BIGINT_H__