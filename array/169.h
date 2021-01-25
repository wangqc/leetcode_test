//
// Created by 王秋城 on 2021/1/25.
//

#ifndef LEETCODE_TEST_169_H
#define LEETCODE_TEST_169_H

#include "../common.h"

class Solution {
public:
    // 最简单做法， 哈希表
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& n : nums) {
            if (mp.find(n) == mp.end()) {
                mp[n] = 1;
            } else {
                mp[n]++;
            }
        }
        int max = 0, ret;
        for (auto& kv : mp) {
            if (kv.second > max) {
                max = kv.second;
                ret = kv.first;
            }
        }
        return ret;
    }

    int majorityElementV2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

    // 投票算法， 牛逼！
    int majorityElementV3(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (candidate == nums[i]) {
                count++;
            } else if (--count < 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }

};

#endif //LEETCODE_TEST_169_H
