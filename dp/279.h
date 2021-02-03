//
// Created by 王秋城 on 2021/2/3.
//

#ifndef LEETCODE_TEST_279_H
#define LEETCODE_TEST_279_H

#include "../common.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <=n; i++) {
            dp[i] = i;
            for (int j = 1; i - j*j >=0; j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};

class SolutionDfs {
public:
    int numSquares(int n) {
        map<int, int> mp;
        mp[0] = 0;
        return helper(n, mp);
    }

private:
    int helper(int n, map<int,int>& mp) {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        int count = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            count = min(count, helper(n - i*i, mp) + 1);
        }
        mp[n] = count;
        return count;
    }
};


class SolutionBfs {
public:
    int numSquares(int n) {
        queue<int> q;
        set<int> st;
        int level = 0;
        q.push(n);
        while(!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                for (int j = 1; j * j <= cur; ++j) {
                    int next = cur - j*j;
                    if (next == 0) {
                        return level;
                    }
                    if (st.find(next) == st.end()) {
                        q.push(next);
                        st.insert(next);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};

class SolutionMath {
public:
    int numSquares(int n) {
        set<int> st1;
        for (int i = 1; i * i <= n; ++i) {
            st1.insert(i*i);
        }
        if (st1.find(n) != st1.end()) {
            return 1;
        }

        set<int> st2;
        for (auto& i: st1) {
            for (auto& j : st1) {
                st2.insert(i + j);
            }
        }
        if (st2.find(n) != st2.end()) {
            return 2;
        }

        for (auto& i : st1) {
            if (st2.find(n - i) != st2.end()) {
                return 3;
            }
        }

        return 4;
    }
};

#endif //LEETCODE_TEST_279_H
