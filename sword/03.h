//
// Created by 王秋城 on 2021/3/16.
//

#ifndef LEETCODE_TEST_03_H
#define LEETCODE_TEST_03_H

#include "../common.h"

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& n : nums) {
            if (s.find(n) != s.end()) {
                return n;
            }
            s.insert(n);
        }
        return -1;
    }
};

// 原地排序，一个萝卜一个坑
class SolutionBetter {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_TEST_03_H
