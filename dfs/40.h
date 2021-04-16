//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_40_H
#define LEETCODE_TEST_40_H

#include <vector>

using namespace std;


// TODO: not finish
class Solution {
public:
    void back_trace(vector<vector<int>>& ret, vector<int>& v, int start_idx, const vector<int>& candidates, int result) {
        if (result == 0) {
            ret.emplace_back(v);
            return;
        }
        if (start_idx >= candidates.size()) {
            return;
        }
        for (int i = start_idx; i < candidates.size(); ++i) {
            v.push_back(candidates[i]);
            back_trace(ret, v, i + 1, candidates, result - candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        vector<int> v;
        back_trace(ret, v, 0, candidates, target);
        return ret;
    }
};


#endif //LEETCODE_TEST_40_H
