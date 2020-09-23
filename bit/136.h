//
// Created by wangqiucheng on 2020/9/15.
//

#ifndef LEETCODE_TEST_136_H
#define LEETCODE_TEST_136_H

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ret = ret^nums[i];
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_136_H
