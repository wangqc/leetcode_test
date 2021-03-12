//
// Created by 王秋城 on 2021/3/12.
//

#ifndef LEETCODE_TEST_581_H
#define LEETCODE_TEST_581_H

#include "../common.h"


// O(nlogn) time, O(n) space
class SolutionEasy {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> dup(nums.begin(), nums.end());
        sort(dup.begin(), dup.end());
        int start = 0, end = nums.size() - 1;
        for (; start < nums.size(); ++start) {
            if (nums[start] != dup[start]) {
                break;
            }
        }
        if (start > end) {
            return 0;
        }
        for (; end >= 0; --end) {
            if (nums[end] != dup[end]) {
                break;
            }
        }
        return end - start + 1;
    }
};

// O(n) time, O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                min = std::min(min, nums[i+1]);
                max = std::max(max, nums[i]);
            }
        }

        int left = nums.size(), right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > min) {
                left = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >=0; --i) {
            if (nums[i] < max) {
                right = i;
                break;
            }
        }
        return right < left ? 0 : right - left + 1;

    }
};


#endif //LEETCODE_TEST_581_H
