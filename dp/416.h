//
// Created by 王秋城 on 2020/10/13.
//

#ifndef LEETCODE_TEST_416_H
#define LEETCODE_TEST_416_H

#include <vector>

using namespace std;

class Solution {
public:
    // 二维dp
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return true;
        }
        int sum = 0;
        int max = nums[0];
        for (auto& ele : nums) {
            sum += ele;
            max = std::max(max, ele);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (max > target) {
            return false;
        }
        vector<vector<bool>> dp(size, vector<bool>(target + 1, false));
        for (int i = 0; i < size; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            for (int j = 1; j <= target; ++j) {
                if (j >= num) {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size-1][target];
    }

    bool canPartitionV2(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return true;
        }
        int sum = 0;
        int max = nums[0];
        for (auto& ele : nums) {
            sum += ele;
            max = std::max(max, ele);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (max > target) {
            return false;
        }
        vector<bool> dp(target + 1, false);
        dp[nums[0]] = true;
        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] | dp[j-num];
            }
        }
        return dp[target];
    }
};

#endif //LEETCODE_TEST_416_H
