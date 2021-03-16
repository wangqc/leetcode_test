//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_10_2_H
#define LEETCODE_TEST_10_2_H

#include "../common.h"

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = a;
            a = b;
            b = (b + tmp) % 1000000007;
        }
        return b;
    }
};

#endif //LEETCODE_TEST_10_2_H
