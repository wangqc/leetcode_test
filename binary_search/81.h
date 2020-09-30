//
// Created by wangqiucheng on 2020/9/29.
//

#ifndef LEETCODE_TEST_81_H
#define LEETCODE_TEST_81_H

#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]){
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[mid] != nums[right]) {
                    left = mid + 1;
                } else {
                    left++;
                }
            }
        }
        return false;
    }
};

#endif //LEETCODE_TEST_81_H
