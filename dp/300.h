//
// Created by 王秋城 on 2021/2/4.
//

#ifndef LEETCODE_TEST_300_H
#define LEETCODE_TEST_300_H

#include "../common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};

#endif //LEETCODE_TEST_300_H
