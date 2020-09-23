//
// Created by wangqiucheng on 2020/9/22.
//

#ifndef LEETCODE_TEST_201_H
#define LEETCODE_TEST_201_H

#include <vector>
#include "stdint.h"

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            cnt++;
        }
        return m << cnt;
    }

    int rangeBitwiseAndV2(int m, int n) {
        while (m < n) {
            n = n & (n-1);
        }
        return n;
    }
};

#endif //LEETCODE_TEST_201_H
