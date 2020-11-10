//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_69_H
#define LEETCODE_TEST_69_H

class Solution {
public:
    int mySqrt(int x) {
        long long start_x = 0;
        long long end_x = x;
        long long lx = x;
        while (start_x <= end_x) {
            long long middle_x = (start_x + end_x) / 2;
            long long square_m_x = middle_x * middle_x;
            if (square_m_x == lx) {
                return middle_x;
            } else if (square_m_x < lx) {
                start_x = middle_x + 1;
            } else {
                end_x = middle_x - 1;
            }
        }
        return start_x - 1;
    }
};

#endif //LEETCODE_TEST_69_H
