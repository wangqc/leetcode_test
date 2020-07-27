//
// Created by wangqiucheng on 2020/7/9.
//

#ifndef LEETCODE_TEST_35_H
#define LEETCODE_TEST_35_H

#include <vector>

class Solution {
public:
    // 典型的二分查找
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return mid;
    }
};

#endif //LEETCODE_TEST_35_H
