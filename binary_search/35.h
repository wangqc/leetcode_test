//
// Created by wangqiucheng on 2020/9/23.
//

#ifndef LEETCODE_TEST_35_H
#define LEETCODE_TEST_35_H

#include <vector>

using namespace std;

class Solution {
public:
    //　模板化做法，　最后剩下两个来进行比较就行
    int searchInsert(vector<int>& nums, int target) {
        int mid, start = 0, end = nums.size()-1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            cout << mid << endl;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (nums[start] >= target) {
            return start;
        } else if (nums[end] >= target) {
            return end;
        }
        return end + 1;
    }

    //　高效做法
    int searchInsertV2(vector<int>& nums, int target) {
        int start = 0, mid, end = nums.size() - 1, ret = nums.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (target <= nums[mid]) {
                ret = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_35_H
