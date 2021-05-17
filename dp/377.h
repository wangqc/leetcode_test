//
// Created by 王秋城 on 2021/5/17.
//

#ifndef LEETCODE_TEST_377_H
#define LEETCODE_TEST_377_H

#include "../common.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto& num : nums) {
            for (int j = num; j <= target; ++j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[target];
    }
};

#endif //LEETCODE_TEST_377_H
