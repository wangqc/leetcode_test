//
// Created by wangqiucheng on 2020/9/9.
//

#ifndef LEETCODE_TEST_39_H
#define LEETCODE_TEST_39_H

#include "../common.h"

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

class SolutionTwo {
public:
    vector<vector<int>> ret;

    void dfs(const vector<int>& candidates, int first, int target, vector<int>& path) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        for (int i = first; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            // 这个地方传入的idx是i的话，说明不会再往回遍历
            dfs(candidates, i, target-candidates[i], path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, 0, target, path);
        return ret;
    }
};

#endif //LEETCODE_TEST_39_H
