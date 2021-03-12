//
// Created by 王秋城 on 2021/3/12.
//

#ifndef LEETCODE_TEST_560_H
#define LEETCODE_TEST_560_H

#include "../common.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};

#endif //LEETCODE_TEST_560_H
