//
// Created by 王秋城 on 2020/11/10.
//

#ifndef LEETCODE_TEST_31_H
#define LEETCODE_TEST_31_H

#include <vector>

using namespace std;

class Solution {
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }
        int i;
        for (i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums, 0, size - 1);
            return;
        }
        int j;
        for (j = size - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        reverse(nums, i + 1, size - 1);
        return;
    }
};

#endif //LEETCODE_TEST_31_H
