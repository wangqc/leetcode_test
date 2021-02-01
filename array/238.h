//
// Created by 王秋城 on 2021/2/1.
//

#ifndef LEETCODE_TEST_238_H
#define LEETCODE_TEST_238_H

#include "../common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size, 1);
        for (int i = 1; i < size; ++i) {
            answer[i] = answer[i-1] * nums[i - 1];
        }
        int R = 1;
        for (int i = size - 2; i >= 0; --i) {
            R *= nums[i + 1];
            answer[i] *= R;
        }
        return answer;
    }
};

#endif //LEETCODE_TEST_238_H
