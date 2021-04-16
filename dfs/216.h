//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_216_H
#define LEETCODE_TEST_216_H

#include "../common.h"
using namespace std;

class Solution {
public:
    void back_trace(vector<vector<int>>& ret, vector<int>& v, int start_idx, int k, int result) {
        if (k == 0 && result == 0) {
            ret.emplace_back(v);
            return;
        }
        if (k == 0 || result == 0) {
            return;
        }
        for (int i = start_idx; i <= 9; ++i) {
            v.push_back(i);
            back_trace(ret, v, i + 1, k - 1, result - i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationsum3(int k, int n) {
        if (n <= 0 || n > 45) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        vector<int> v;
        back_trace(ret, v, 1, k, n);
        return ret;
    }
};


class SolutionTwo {
public:
    vector<vector<int>> ret;

    void dfs(int cnt, int target, int start_idx, vector<int>& path) {
        if (cnt == 0 && target == 0) {
            ret.push_back(path);
            return;
        }
        if (cnt == 0 || target == 0) {
            return;
        }
        for (int i = start_idx; i <= 9; ++i) {
            path.push_back(i);
            dfs(cnt-1, target-i, i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if (n <= 0 || n > 45) {
            return vector<vector<int>>();
        }
        vector<int> path;
        dfs(k, n, 1, path);
        return ret;
    }
};

#endif //LEETCODE_TEST_216_H
