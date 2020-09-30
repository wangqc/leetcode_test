//
// Created by wangqiucheng on 2020/9/30.
//

#ifndef LEETCODE_TEST_120_H
#define LEETCODE_TEST_120_H

#include <vector>

using namespace std;

class Solution {
public:
    // 使用的是O(n2)空间, 可优化
    int minimumTotal(vector<vector<int>>& triangle) {
        int rsize = triangle.size();
        if (rsize == 0) {
            return 0;
        }
        vector<vector<int>> dp(rsize, vector<int>(rsize, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < rsize; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int ret = dp[rsize - 1][0];
        for (int i = 1; i < rsize; ++i) {
            ret = min(ret, dp[rsize - 1][i]);
        }
        return ret;
    }


    // 使用O(n)空间
    int minimumTotalV2(vector<vector<int>>& triangle) {
        int rsize = triangle.size();
        if (rsize == 0) {
            return 0;
        }
        vector<int> dp(rsize, 0);
        dp[0] = triangle[0][0];
        for (int i = 1 ; i < rsize; ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--)  {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        int ret = dp[0];
        for (int i = 1; i < rsize; ++i) {
            ret = min(dp[i], ret);
        }
        return ret;
    }

    // 自底向上
    int minimumTotalV3(vector<vector<int>>& triangle) {
        int rsize = triangle.size();
        vector<int> dp(rsize + 1, 0);
        for (int i = rsize - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

#endif //LEETCODE_TEST_120_H
