//
// Created by wangqiucheng on 2020/9/29.
//

#ifndef LEETCODE_TEST_154_H
#define LEETCODE_TEST_154_H

#include <vector>

using namespace std;

class Solution {
public:
    // most stupid solution
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        int min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return min;
    }

    // binary search
    int findMinV2(vector<int>& nums) {
        int mid, left = 0, right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[mid];
    }
};

#endif //LEETCODE_TEST_154_H
