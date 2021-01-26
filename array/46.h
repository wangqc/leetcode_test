//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_46_H
#define LEETCODE_TEST_46_H

#include "../common.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        unordered_set<int> include_idx;
        vector<int> v;
        back_trace(nums, ret, include_idx, v);
        return ret;
    }

private:
    void back_trace(const vector<int>& nums, vector<vector<int>>& ret, unordered_set<int>& include_idx, vector<int>& v) {
        if (v.size() == nums.size()) {
            ret.push_back(v);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (include_idx.find(i) != include_idx.end()) {
                continue;
            }
            v.push_back(nums[i]);
            include_idx.insert(i);
            back_trace(nums, ret, include_idx, v);
            v.pop_back();
            include_idx.erase(i);
        }
    }
};

#endif //LEETCODE_TEST_46_H
