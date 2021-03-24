//
// Created by 王秋城 on 2021/3/24.
//

#ifndef LEETCODE_TEST_456_H
#define LEETCODE_TEST_456_H

#include "../common.h"

// O(N3)傻逼算法
class SolutionStupid {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                if (nums[j] <= nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[k] >= nums[j]) {
                        continue;
                    }
                    if (nums[k] <= nums[i]) {
                        continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};


// 两头缩减，O(N2)做法
class SolutionStupidV2 {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int left_min = nums[0];
        for (int j = 1; j < nums.size() - 1; ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if (left_min < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
            left_min = min(nums[j], left_min);
        }

        return false;
    }
};


// 单调栈解法
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(), k = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < k) return true;
            while(!st.empty() and st.top() < nums[i]) {
                k = max(k,st.top()); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
#endif //LEETCODE_TEST_456_H
