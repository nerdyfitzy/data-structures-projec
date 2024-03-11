#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <string>
#include "SLList.h"
#include <iostream>


namespace ds {
    class BigInt {
        private:
            SLList<int> digits; // stores the digits of the BigInt
            int length;
        public:
            BigInt(const std::string &val = "") {
                for (int j = 0; j < val.length(); j++) {
                    digits.addLast(val[j] - '0');
                }

                length = digits.size();
            };
            int size() {
                return length;
            }
            int getDigit(int i) {
                return i < length ? digits.get(i) : 0;
            }

            void addFirst(int i) {
                digits.addFirst(i);
            }
            void addLast(int i) {
                digits.addLast(i);
            }

            void output() {
                for(int i = 0; i < this->length; i++) {
                    std::cout << getDigit(i);
                }
                std::cout << std::endl;
            }
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