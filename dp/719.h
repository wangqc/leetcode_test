//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_719_H
#define LEETCODE_TEST_719_H

#include "../common.h"

class Solution {
public:
    int maxProfitMoreSpace(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[len-1][0];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int hold, cash, pre_hold, pre_cash;
        hold = pre_hold = -prices[0];
        cash = pre_cash = 0;
        for (int i = 1; i < len; ++i) {
            cash = std::max(pre_cash, pre_hold + prices[i] - fee);
            hold = std::max(pre_hold, pre_cash - prices[i]);

            pre_cash = cash;
            pre_hold = hold;
        }
        return cash;
    }
};


class SolutionGreedy {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < len; ++i) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            }
            if (prices[i] > buy) {
                profit += (prices[i] - buy);
                buy = prices[i];
            }
        }
        return profit;
    }
};

#endif //LEETCODE_TEST_719_H
