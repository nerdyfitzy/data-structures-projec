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
                bool garbage = true;
                for (int j = 0; j < val.length(); j++) {
                    //both conditionals meant for garbage cleaning any 
                    if(val[j] != '0') garbage = false;
                    if(!garbage || val.length() == 1 || j == val.length() - 1) digits.addLast(val[j] - '0');
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

            void output();
            static void add(BigInt &a, BigInt &b, BigInt &c);
            static void subtract(BigInt &a, BigInt &b, BigInt &c);
            friend BigInt operator+(BigInt  &a, BigInt  &b);
            friend BigInt operator-(BigInt &a, BigInt &b);
            friend bool operator>(BigInt &a, BigInt &b);
    };


    //2150
    //0452

    //   8

}

#endif __BIGINT_H__