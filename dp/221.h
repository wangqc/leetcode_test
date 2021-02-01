//
// Created by 王秋城 on 2021/2/1.
//

#ifndef LEETCODE_TEST_221_H
#define LEETCODE_TEST_221_H

//https://leetcode-cn.com/problems/maximal-square/

#include "../common.h"

class Solution {
public:
    // 可以考虑优化空间复杂度的，利用滚动数组
    int maximalSquareMoreSpace(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int max = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i + 1][j + 1] = 0;
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
                    if (dp[i + 1][j + 1] > max) {
                        max = dp[i + 1][j + 1];
                    }
                }
            }
        }
        return max * max;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> dp(col + 1, 0);
        int max = 0;
        for (int i = 0; i < row; ++i) {
            int prev = 0;
            for (int j = 0; j < col; ++j) {
                int tmp = dp[j+1];
                if (matrix[i][j] == '0') {
                    dp[j+1] = 0;
                } else {
                    dp[j + 1] = min(prev, min(dp[j], dp[j+1])) + 1;
                    if (dp[j+1] > max) {
                        max = dp[j+1];
                    }
                }
                prev = tmp;
            }
        }
        return max*max;
    }
};

#endif //LEETCODE_TEST_221_H
