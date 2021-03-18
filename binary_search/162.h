//
// Created by 王秋城 on 2021/3/18.
//

#ifndef LEETCODE_TEST_162_H
#define LEETCODE_TEST_162_H

#include "../common.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            if (right - left == 1) {
                return ((nums[left] > nums[right]) ? left : right);
            }
            mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[mid-1]) {
                if (nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_162_H
