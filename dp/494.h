//
// Created by 王秋城 on 2021/3/3.
//

#ifndef LEETCODE_TEST_494_H
#define LEETCODE_TEST_494_H

#include "../common.h"

class SolutionOriginal {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int num = 0;
        dfs(nums, 0, 0, S, num);
        return num;
    }

private:
    void dfs(vector<int>& nums, int cur_idx, int cur_sum, int S, int& num) {
        if (cur_idx == nums.size()) {
            if (cur_sum == S) {
                num++;
            }
            return;
        }
        dfs(nums, cur_idx + 1, cur_sum + nums[cur_idx], S, num);
        dfs(nums, cur_idx + 1, cur_sum - nums[cur_idx], S, num);
    }
};


class SolutionGood {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000 || S < -1000) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(2001, 0));
        dp[0][nums[0]+1000] = 1;
        dp[0][-nums[0]+1000] += 1;  // 神来之笔，考虑0的情况
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < 2001; ++j) {
                if (dp[i-1][j] == 0) {
                    continue;
                }
                dp[i][j+nums[i]] += dp[i-1][j];
                dp[i][j-nums[i]] += dp[i-1][j];
            }
        }
        return dp[nums.size()-1][S+1000];
    }
};


class SolutionBetter {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000 || S < -1000) {
            return 0;
        }
        vector<int> dp(2001, 0);
        dp[nums[0]+1000] = 1;
        dp[-nums[0]+1000] += 1;  // 神来之笔，考虑0的情况
        for (int i = 1; i < nums.size(); ++i) {
            vector<int> next(2001, 0);
            for (int j = 0; j < 2001; ++j) {
                if (dp[j] == 0) {
                    continue;
                }
                next[j+nums[i]] += dp[j];
                next[j-nums[i]] += dp[j];
            }
            dp.swap(next);
        }
        return dp[S+1000];
    }
};


class SolutionMoreSpace {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (target > 1000 || target < -1000) return 0;
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= 2000; ++j) {
                int minus = 0;
                int plus = 0;
                if (j - nums[i] >= 0) {
                    plus = dp[i - 1][j - nums[i]];
                }
                if (j + nums[i] <= 2000) {
                    minus = dp[i - 1][j + nums[i]];
                }
                dp[i][j] = minus + plus;
            }
        }
        return dp[len - 1][target + 1000];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto& n : nums) {
            sum += n;
        }
        if (target > sum || (target + sum) % 2 == 1) return 0;
        int t = (sum + target) / 2;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = t; j >= nums[i]; --j) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[t];
    }
};
#endif //LEETCODE_TEST_494_H
