//
// Created by 王秋城 on 2020/9/30.
//

#ifndef LEETCODE_TEST_70_H
#define LEETCODE_TEST_70_H

class Solution {
public:
    // 最简单的递归，耗时指数型上升
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
#endif //LEETCODE_TEST_70_H
