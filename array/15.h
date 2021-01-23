//
// Created by 王秋城 on 2021/1/23.
//

#ifndef LEETCODE_TEST_15_H
#define LEETCODE_TEST_15_H

#include "../common.h"

class Solution {
public:
    // 难点主要是在去重上面
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if (size <= 2) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        for (int i = 0; i < size - 2; ++i) {
            if (nums[i] > 0) {
                return ret;
            }
            if (i >= 1 && nums[i] == nums[i-1]) {
                continue;
            }
            int start = i + 1;
            int end = size - 1;
            int target = 0 - nums[i];
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == target) {
                    ret.push_back({nums[i], nums[start], nums[end]});
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;
                } else if (sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_15_H
