//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_448_H
#define LEETCODE_TEST_448_H

#include "../common.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int next_idx = (nums[i] - 1) % size;
            nums[next_idx] += size;
        }
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
            if (nums[i] <= size) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_448_H
