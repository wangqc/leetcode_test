//
// Created by 王秋城 on 2021/4/16.
//

#ifndef LEETCODE_TEST_90_H
#define LEETCODE_TEST_90_H

#include "../common.h"

class Solution {
public:
    vector<vector<int>> ret;

    void dfs(const vector<int>& nums, int cur_idx, vector<int>& path, bool choose_before) {
        if (cur_idx == nums.size()) {
            ret.push_back(path);
            return;
        }
        dfs(nums, cur_idx + 1, path, false);
        if (cur_idx > 0 && !choose_before && nums[cur_idx] == nums[cur_idx-1]) {
            return;
        }
        path.push_back(nums[cur_idx]);
        dfs(nums, cur_idx + 1, path, true);
        path.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path, false);
        return ret;
    }
};

#endif //LEETCODE_TEST_90_H
