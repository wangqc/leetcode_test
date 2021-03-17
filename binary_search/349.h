//
// Created by 王秋城 on 2021/3/17.
//

#ifndef LEETCODE_TEST_349_H
#define LEETCODE_TEST_349_H

#include "../common.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<int> ret;
        for (auto &i : st1) {
            if (st2.find(i) != st2.end()) {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};
#endif //LEETCODE_TEST_349_H
