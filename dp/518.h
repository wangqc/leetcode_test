//
// Created by 王秋城 on 2021/5/17.
//

#ifndef LEETCODE_TEST_518_H
#define LEETCODE_TEST_518_H

#include "../common.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto& coin : coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};

#endif //LEETCODE_TEST_518_H
