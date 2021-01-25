//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_283_H
#define LEETCODE_TEST_283_H

#include "../common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (idx == i) {
                    idx++;
                } else {
                    nums[idx++] = nums[i];
                }
            }
        }
        for (; idx < nums.size(); ++idx) {
            nums[idx] = 0;
        }
    }
};

#endif //LEETCODE_TEST_283_H
