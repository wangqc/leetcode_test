//
// Created by 王秋城 on 2021/4/6.
//

#ifndef LEETCODE_TEST_53_1_H
#define LEETCODE_TEST_53_1_H

#include "../common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;
        while (left < right) {
            mid = left + ((right - left) >> 2);
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (left >= nums.size()) {
            return 0;
        }
        int left_most = left;
        left = 0, right = nums.size();
        while (left < right) {
            mid = left + ((right - left) >> 2);
            if (nums[mid] < target + 1) left = mid + 1;
            else right = mid;
        }
        int right_most = left - 1;
        return (right_most - left_most + 1);
    }
};

#endif //LEETCODE_TEST_53_1_H
