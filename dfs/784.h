//
// Created by 王秋城 on 2021/4/13.
//

#ifndef LEETCODE_TEST_784_H
#define LEETCODE_TEST_784_H

#include "../common.h"

class SolutionBfs {
    vector<string> ret;
    queue<string> q;
public:
    vector<string> letterCasePermutation(string S) {
        for (int i = 0; i < S.size(); ++i) {
            vector<char> chs;
            chs.push_back(S[i]);
            if (S[i] >= 'a' && S[i] <= 'z') {
                chs.push_back(S[i] - 'a' + 'A');
            }
            if (S[i] >= 'A' && S[i] <= 'Z') {
                chs.push_back(S[i] - 'A' + 'a');
            }
            if (q.empty()) {
                for (auto& ch : chs) {
                    q.push(string(1, ch));
                }
            } else {
                int size = q.size();
                for (int j = 0; j < size; ++j) {
                    for (auto& ch : chs) {
                        q.push(q.front() + ch);
                    }
                    q.pop();
                }
            }
        }
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};


class Solution {
    vector<string> ret;

    void dfs(const string& S, int i, string path) {
        if (i == S.size()) {
            ret.push_back(path);
            return;
        }
        dfs(S, i + 1, path + S[i]);
        if (S[i] >= 'a' && S[i] <= 'z') {
            dfs(S, i + 1, path + char(S[i] - 'a' + 'A'));
        }
        if (S[i] >= 'A' && S[i] <= 'Z') {
            dfs(S, i + 1, path + char(S[i] - 'A' + 'a'));
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0, "");
        return ret;
    }
};

#endif //LEETCODE_TEST_784_H
