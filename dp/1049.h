//
// Created by 王秋城 on 2021/5/15.
//

#ifndef LEETCODE_TEST_1049_H
#define LEETCODE_TEST_1049_H

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& n : stones) {
            sum += n;
        }
        vector<bool> dp(2 * sum + 1, false);
        dp[stones[0] + sum] = true;
        dp[-stones[0] + sum] = true;
        for (int i = 1; i < stones.size(); ++i) {
            vector<bool> next(2 * sum + 1, false);
            next[stones[i] + sum] = dp[stones[i] + sum];
            next[-stones[i] + sum] = dp[-stones[i] + sum];


        }
    }
};

#endif //LEETCODE_TEST_1049_H
