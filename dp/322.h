//
// Created by 王秋城 on 2021/2/3.
//

#ifndef LEETCODE_TEST_322_H
#define LEETCODE_TEST_322_H

#include "../common.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, -1);
        set<int> coins_set(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i) {
            if (coins_set.find(i) != coins_set.end()) {
                dp[i] = 1;
                continue;
            }
            for (auto& coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i-coin] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i-coin] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};

#endif //LEETCODE_TEST_322_H
