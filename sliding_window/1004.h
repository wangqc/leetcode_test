//
// Created by 王秋城 on 2021/2/19.
//

#ifndef LEETCODE_TEST_1004_H
#define LEETCODE_TEST_1004_H

#include "../common.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, zeros = 0, left = 0;
        for (int right = 0; right < A.size(); ++right) {
            if (A[right] == 0) {
                zeros++;
            }
            while (zeros > K) {
                if (A[left++] == 0) {
                    zeros--;
                }
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


// 牛逼的解法
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, len = A.size();
        while (r < len) {
            if (A[r++] == 0) K--;
            if (K < 0 && A[l++] == 0) K++;
        }
        return r-l;
    }
};
#endif //LEETCODE_TEST_1004_H
