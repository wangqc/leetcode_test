//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_123_H
#define LEETCODE_TEST_123_H

#include "../common.h"

class Solution {
public:
    int maxProfitMoreSpace(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(5));
        dp[0][0] = dp[0][2] = dp[0][4] = 0;
        dp[0][1] = dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = std::max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = std::max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = std::max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        return dp[prices.size()-1][4];
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int buy1, sell1, buy2, sell2;
        buy1 = buy2 = -prices[0];
        sell1 = sell2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy1 = std::max(buy1, -prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

#endif //LEETCODE_TEST_123_H
