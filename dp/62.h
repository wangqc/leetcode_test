//
// Created by wangqiucheng on 2020/9/30.
//

#ifndef LEETCODE_TEST_62_H
#define LEETCODE_TEST_62_H

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j+1] = dp[j] + dp[j+1];
            }
        }
        return dp[n];
    }
};

#endif //LEETCODE_TEST_62_H
