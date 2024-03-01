#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <string.h>
#include "AList.h"


namespace ds {
    class BigInt {
        private:
            AList<int> digits; // stores the digits of the BigInt

        public:
            BigInt(const string &val = "") {
                for (int j = 0; j < val.length(); j++) {
                digits.addLast(val[j] - '0');
                }
            };

            BigInt operator+(const BigInt &a, const BigInt &b);
            BigInt operator-(const BigInt &a, const BigInt &b);
    };


    BigInt & BigInt::operator+(const BigInt &a, const BigInt &b) {

    }

    BigInt & BigInt::operator-(const BigInt &a, const BigInt &b) {

    }
}

#endif __BIGINT_H__