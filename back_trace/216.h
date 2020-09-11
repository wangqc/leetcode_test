//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_216_H
#define LEETCODE_TEST_216_H

#include <vector>

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

#endif //LEETCODE_TEST_216_H
