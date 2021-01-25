//
// Created by 王秋城 on 2021/1/24.
//

#ifndef LEETCODE_TEST_34_H
#define LEETCODE_TEST_34_H

#include "../common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int left_range = -1, right_range = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    left_range = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (left == -1) {
            return vector<int>{-1, -1};
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    right_range = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            }
        }
        if (right_range == -1) {
            return vector<int>{-1, -1};
        }
        vector<int> ret;
        ret.push_back(left_range);
        ret.push_back(right_range);
        return ret;
    }
};


#endif //LEETCODE_TEST_34_H
