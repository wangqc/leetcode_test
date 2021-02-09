//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_122_H
#define LEETCODE_TEST_122_H

#include "../common.h"

//可以多次交易
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    // 贪心算法
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int res = 0;
        for (int i = 1; i < len; ++i) {
            if (prices[i] > prices[i-1]) {
                res += (prices[i] - prices[i-1]);
            }
        }
        return res;
    }
};


class SolutionDP {
public:
    // 动态规划算法
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<int> cash(len);
        vector<int> store(len);
        cash[0] = 0;
        store[0] = -prices[0];

        for (int i = 1; i < len; ++i) {
            cash[i] = std::max(cash[i-1], store[i-1]+prices[i]);
            store[i] = std::max(store[i-1], cash[i-1]-prices[i]);
        }

        return cash[len-1];
    }


    int maxProfitV2(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[len-1][0];
    }

    int maxProfitV3(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int cash, hold, pre_cash, pre_hold;
        pre_cash = 0;
        pre_hold = -prices[0];
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            cash = std::max(pre_cash, pre_hold + prices[i]);
            hold = std::max(pre_hold, pre_cash - prices[i]);
            pre_cash = cash;
            pre_hold = hold;
        }
        return cash;
    }
};

#endif //LEETCODE_TEST_122_H
