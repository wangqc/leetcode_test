//
// Created by 王秋城 on 2020/11/6.
//

#ifndef LEETCODE_TEST_38_H
#define LEETCODE_TEST_38_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp{"1", "11", "21", "1211", "111221"};
        if (n < dp.size()) {
            return dp[n];
        }
        int dp_size = dp.size();
        for (int i = dp_size - 1; i < n; ++i) {
            char prev_ch = dp[i][0];
            int prev_cnt = 1;
            string count_str;
            for (int j = 1; j < dp[i].size(); ++j) {
                if (dp[i][j] != prev_ch) {
                    count_str += (prev_cnt+'0');
                    count_str += prev_ch;
                    prev_ch = dp[i][j];
                    prev_cnt = 1;
                } else {
                    prev_cnt++;
                }
            }
            count_str += (prev_cnt+'0');
            count_str += prev_ch;
            dp.push_back(count_str);
        }
        return dp[n-1];
    }
};

#endif //LEETCODE_TEST_38_H
