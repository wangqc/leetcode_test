//
// Created by wangqiucheng on 2020/9/9.
//

#ifndef LEETCODE_TEST_39_H
#define LEETCODE_TEST_39_H

#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> v;
        back_trace(candidates, v, ret, 0, target);
        return ret;
    }

private:
    void back_trace(const vector<int>& candidates, vector<int>& v, vector<vector<int>>& ret, int start_idx, int target_after_sum) {
        if (target_after_sum == 0) {
            ret.emplace_back(v);
            return;
        }
        if (target_after_sum < 0) {
            return;
        }
        for (int i = start_idx; i < candidates.size(); ++i) {
            v.push_back(candidates[i]);
            back_trace(candidates, v, ret, i, target_after_sum - candidates[i]);
            v.pop_back();
        }
    }
};

#endif //LEETCODE_TEST_39_H
