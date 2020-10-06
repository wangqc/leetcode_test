//
// Created by 王秋城 on 2020/9/30.
//

#ifndef LEETCODE_TEST_70_H
#define LEETCODE_TEST_70_H

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // 最简单的递归，耗时指数型上升
    int climbStairsFail(int n) {
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

    map<long long, long long> hash;
    int climbStairsRecur(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (hash.find(n) != hash.end()) {
            return hash[n];
        }
        hash[n-1] = climbStairsRecur(n-1);
        hash[n-2] = climbStairsRecur(n-2);
        return hash[n-1] + hash[n-2];
    }

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<long long> dp{1,2};
        int cur_bool_idx = 0;
        for (int i = 3; i < n; ++i) {
            dp[cur_bool_idx] = dp[0] + dp[1];
            cur_bool_idx = !cur_bool_idx;
        }
        return dp[!cur_bool_idx];
    }

};
#endif //LEETCODE_TEST_70_H
