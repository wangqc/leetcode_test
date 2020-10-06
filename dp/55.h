//
// Created by 王秋城 on 2020/10/1.
//

#ifndef LEETCODE_TEST_55_H
#define LEETCODE_TEST_55_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canJumpStupid(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        int size = nums.size();
        for (int cur_idx = 0; cur_idx < size; ++cur_idx) {
            int step = nums[cur_idx];
            int max_jump_pos = min((cur_idx + step), size - 1);
            for (int i = max_jump_pos; i > cur_idx; --i) {
                if (dp[i]) {
                    break;
                }
                dp[i] = true;
            }
        }
        return dp[size-1];
    }

    // beautiful solution
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                return false;
            }
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

#endif //LEETCODE_TEST_55_H
