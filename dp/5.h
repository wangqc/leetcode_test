//
// Created by wangqiucheng on 2020/10/19.
//

#ifndef LEETCODE_TEST_5_H
#define LEETCODE_TEST_5_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    // 时间较长
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true;

        }
        int start_idx = 0;
        int max_len = 1;
        for (int i = 0; i < size - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start_idx = i;
                max_len = 2;
            }
        }
        for (int span = 2; span < size; ++span) {
            for (int idx = 0; idx < size - span; ++idx) {
                if (s[idx] == s[idx + span] && dp[idx + 1][idx + span - 1]) {
                    dp[idx][idx + span] = true;
                    start_idx = idx;
                    max_len = span + 1;
                }
            }
        }
        return s.substr(start_idx, max_len);
    }


    pair<int, int> span(const string& s ,int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return make_pair<int, int>(left+1, right-1);
    }

    // 比较优秀的解法了
    string longestPalindromeV2(string s) {
        int size = s.size();
        int left = 0, right = 0;
        for (int i = 1; i < size - 1; ++i) {
            pair<int, int> p = span(s, i, i);
            if (p.second - p.first > right - left) {
                left = p.first;
                right = p.second;
            }
        }
        for (int i = 0; i < size - 1; ++i) {
            pair<int, int> p = span(s, i, i+1);
            if (p.second - p.first > right - left) {
                left = p.first;
                right = p.second;
            }
        }
        return s.substr(left, right - left + 1);
    }
};

#endif //LEETCODE_TEST_5_H
