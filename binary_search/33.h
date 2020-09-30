//
// Created by wangqiucheng on 2020/9/29.
//

#ifndef LEETCODE_TEST_33_H
#define LEETCODE_TEST_33_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                if (target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left++;
                }
            } else {
                if (target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right--;
                }
            }
        }
        return -1;
    }

    int searchV2(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 需要判断相等
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_33_H
