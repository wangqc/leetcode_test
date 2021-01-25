//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_461_H
#define LEETCODE_TEST_461_H

#include "../common.h"

class Solution {
public:
    // 考虑了负数的情形，但是这里面int不一定是32位
    int hammingDistance(int x, int y) {
        int dis = 0;
        int max_bit = 32;
        while ((x || y) && (max_bit--)) {
            if ((x&1) != (y&1)) {
                dis++;
            }
            x >>= 1;
            y >>= 1;
        }
        return dis;
    }

    int hammingDistanceV2(int x, int y) {
        return bitset<32>(x^y).count();
    }

    // 就是异或的事情了
    int hammingDistanceV3(int x, int y) {
        int z = x ^ y;
        int dis = 0;
        while (z) {
            dis++;
            z = z & (z-1);
        }
        return dis;
    }
};

#endif //LEETCODE_TEST_461_H
