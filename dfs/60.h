//
// Created by 王秋城 on 2021/4/13.
//

#ifndef LEETCODE_TEST_60_H
#define LEETCODE_TEST_60_H

#include "../common.h"

// 模拟法
class SolutionMath {
public:
    string getPermutation(int n, int k) {
        vector<bool> visited(n, false);
        int multi = 1;
        for (int i = 1; i < n; ++i) {
            multi *= i;
        }
        int div = n - 1;
        string ret = string(n, ' ');
        int s_idx = 0;
        k = k - 1;
        while (k) {
            int nth_least = k / multi;
            k = k % multi;
            multi /= div;
            div -= 1;
            int idx = 0;
            for (; idx < n; ++idx) {
                if (visited[idx]) {
                    continue;
                } else {
                    if (nth_least <= 0) {
                        break;
                    } else {
                        nth_least--;
                    }
                }
            }
            visited[idx] = true;
            ret[s_idx++] = ('1' + idx);
        }
        while (s_idx < n) {
            int i;
            for (i = 0; i < n && visited[i]; ++i) {
                ;
            }
            ret[s_idx++] = ('1' + i);
            visited[i] = true;
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> fac;

    void dfs(const int n, int k, int first, vector<bool>& used, int& ret) {
        for (int i = 1; i <= n; ++i) {
            if (used[i-1]) {
                continue;
            }
            if (k > fac[n-first]) {
                k -= fac[n-first];
                continue;
            }
            ret = 10 * ret + i;
            used[i-1] = true;
            dfs(n, k, first + 1, used, ret);
            return;
        }
    }

    string getPermutation(int n, int k) {
        fac.resize(n + 1);
        fac[0] = fac[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i-1] * i;
        }

        vector<bool> used(n ,false);
        int ret = 0;
        dfs(n, k, 1, used, ret);
        return std::to_string(ret);
    }
};

#endif //LEETCODE_TEST_60_H
