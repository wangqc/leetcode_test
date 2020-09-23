//
// Created by wangqiucheng on 2020/9/23.
//

#ifndef LEETCODE_TEST_704_H
#define LEETCODE_TEST_704_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, start = 0, end = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_704_H
