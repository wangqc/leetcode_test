//
// Created by 王秋城 on 2021/3/18.
//

#ifndef LEETCODE_TEST_50_H
#define LEETCODE_TEST_50_H

#include "../common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (equals(x, 1.0)) {
            return 1;
        }
        bool neg = false;
        if (n < 0) {
            neg = true;
        }
        double a = x;
        long b = n;
        if (neg) {
            b = -b;
        }
        double ans = pow(a, b);
        return neg ? 1/ans : ans;
    }

private:
    bool equals(double a, double b) {
        if (abs(a - b) < 1e-6) {
            return true;
        }
        return false;
    }

    double pow(double a, long b) {
        double ta = a;
        long tb = b;
        double left_multi = 1.0;
        while (tb > 1) {
            if (tb & 1) {
                left_multi *= ta;
            }
            tb = tb >> 1;
            ta *= ta;
        }
        return ta * left_multi;
    }
};

#endif //LEETCODE_TEST_50_H
