//
// Created by 王秋城 on 2021/1/28.
//

#ifndef LEETCODE_TEST_152_H
#define LEETCODE_TEST_152_H

#include "../common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_n = nums[0];
        int min_n = nums[0];
        int total_max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp_max_n = max_n;
            int tmp_min_n = min_n;
            max_n = max(tmp_max_n * nums[i], max(tmp_min_n * nums[i], nums[i]));
            min_n = min(tmp_max_n * nums[i], min(tmp_min_n * nums[i], nums[i]));
            total_max = max(total_max, max_n);
        }
        return total_max;
    }
};

#endif //LEETCODE_TEST_152_H
