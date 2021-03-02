//
// Created by 王秋城 on 2021/3/2.
//

#ifndef LEETCODE_TEST_304_H
#define LEETCODE_TEST_304_H

#include "../common.h"

class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        dp.push_back(vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> sub_dp(matrix[0].size() + 1);
            for (int j = 0; j < matrix[0].size(); ++j) {
                sub_dp[j+1] = matrix[i][j] + sub_dp[j] + dp[i][j+1] - dp[i][j];
            }
            dp.push_back(sub_dp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

#endif //LEETCODE_TEST_304_H
