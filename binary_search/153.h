//
// Created by 王秋城 on 2020/9/23.
//

#ifndef LEETCODE_TEST_153_H
#define LEETCODE_TEST_153_H

#include <vector>

using namespace std;

class Solution {
public:
    // 通用模板3
    int findMin(vector<int>& nums) {
        int mid, start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (nums[start] <= nums[mid] && nums[mid] <= nums[end]) {
                return nums[start];
            } else if (nums[start] >= nums[mid] && nums[mid] <= nums[end]) {
                end = mid;
            } else if (nums[start] <= nums[mid] && nums[mid] >= nums[end]) {
                start = mid;
            }
        }
        if (nums[start] < nums[end]) {
            return nums[start];
        }
        return nums[end];
    }

    // 通用模板2
    int findMinV2(vector<int>& nums) {
        int mid, start = 0, end = nums.size() - 1;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return nums[end];
    }
};

#endif //LEETCODE_TEST_153_H
