//
// Created by 王秋城 on 2021/1/27.
//

#ifndef LEETCODE_TEST_139_H
#define LEETCODE_TEST_139_H

#include "../common.h"

class Solution {
public:
    // https://leetcode-cn.com/problems/word-break/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st{wordDict.begin(), wordDict.end()};
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] && st.find(s.substr(j, i - j + 1)) != st.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

#endif //LEETCODE_TEST_139_H
