//
// Created by wangqiucheng on 2020/9/8.
//

#ifndef LEETCODE_TEST_77_H
#define LEETCODE_TEST_77_H

#include <vector>

using namespace std;


// 可以提前剪枝
class Solution {
public:
    void back_trace(int n, vector<vector<int>>& ret, vector<int>& v, int k, int start_idx) {
        if (v.size() + n - start_idx + 1 < k) {
            return;
        }
        if (v.size() == k) {
            ret.emplace_back(v);
        }
        for (int i = start_idx; i <= n; ++i) {
            v.emplace_back(i);
            back_trace(n, ret, v, k, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> v;
        back_trace(n, ret, v, k, 1);
        return ret;
    }
};

#endif //LEETCODE_TEST_77_H
