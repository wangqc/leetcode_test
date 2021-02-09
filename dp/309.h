//
// Created by 王秋城 on 2021/2/9.
//

#ifndef LEETCODE_TEST_309_H
#define LEETCODE_TEST_309_H

#include "../common.h"

class Solution {
public:
    int maxProfitMoreSpace(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<vector<int>> dp(len, vector<int>(3));
        // 第一列表示持有股票；第二列表示持有现金且不在冷却期；第三列表示持有现金不过在冷却期
        // 则dp[i][0]要么是继续持有股票，要么是从非冷却器购入股票
        // dp[i][1]则是继续持有现金，或者是从冷却期到达非冷却期
        // dp[i][2]则是从持有股票转移过来
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < len; ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
        }
        return std::max(dp[len-1][1], dp[len-1][2]);
    }


    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        int hold, just_sold, cash, pre_hold, pre_just_sold, pre_cash;
        hold = pre_hold = -prices[0];
        just_sold = pre_just_sold = 0;
        cash = pre_cash = 0;
        for (int i = 1; i < len; ++i) {
            hold = std::max(pre_hold, cash - prices[i]);
            cash = std::max(pre_cash, pre_just_sold);
            just_sold = pre_hold + prices[i];

            pre_hold = hold;
            pre_cash = cash;
            pre_just_sold = just_sold;
        }
        return std::max(cash, just_sold);
    }
};

#endif //LEETCODE_TEST_309_H
