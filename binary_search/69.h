//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_69_H
#define LEETCODE_TEST_69_H

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, mid;
        while (left < right) {
            mid = right - ((right - left) >> 1);
            long long pow = mid;
            pow *= mid;
            if (pow > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};

#endif //LEETCODE_TEST_69_H
