//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_188_H
#define LEETCODE_TEST_188_H

#include "../common.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || k < 1) {
            return 0;
        }
        vector<int> dp(2*k + 1, 0);
        for (int i = 0; i < k; ++i) {
            dp[2*i+1] = -prices[0];
        }
        for (int i = 1; i < len; ++i) {
            int multi = -1;
            for (int j = 1; j < 2 * k + 1; ++j) {
                dp[j] = std::max(dp[j], dp[j-1] + multi * prices[i]);
                multi = -multi;
            }
        }
        return dp[2*k];
    }
};

#endif //LEETCODE_TEST_188_H
