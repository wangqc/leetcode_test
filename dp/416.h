//
// Created by 王秋城 on 2020/10/13.
//

#ifndef LEETCODE_TEST_416_H
#define LEETCODE_TEST_416_H

#include <vector>

using namespace std;

class SolutionOld {
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

class SolutionMoreSpace {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& n : nums) {
            sum += n;
        }
        if (sum & 0x1) return false;
        int target = sum >> 1;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        if (nums[0] < target) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j == nums[i]) {
                    dp[i][j] = true;
                    continue;
                }
                if (nums[i] < j) {
                    dp[i][j] |= dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[len - 1][target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        int len = nums.size();
        for (int i = 0; i < len; ++i ) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};

#endif //LEETCODE_TEST_416_H
