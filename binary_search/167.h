//
// Created by 王秋城 on 2021/3/17.
//

#ifndef LEETCODE_TEST_167_H
#define LEETCODE_TEST_167_H

#include "../common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> ret(2);
        for (int i = 0; i < numbers.size(); ++i) {
            if (mp.find(target - numbers[i]) != mp.end()) {
                ret[0] = mp[target - numbers[i]];
                ret[1] = i + 1;
                break;
            } else {
                mp[numbers[i]] = i + 1;
            }
        }
        return ret;
    }
};

#endif //LEETCODE_TEST_167_H
