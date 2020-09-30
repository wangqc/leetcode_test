//
// Created by 王秋城 on 2020/9/30.
//

#ifndef LEETCODE_TEST_63_H
#define LEETCODE_TEST_63_H

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        int rsize = obstacleGrid.size();
        int csize = obstacleGrid[0].size();
        vector<int> dp(csize + 1, 0);
        dp[0] = 0;
        for (int j = 0; j < csize; ++j) {
            if (obstacleGrid[0][j] != 1) {
                dp[j+1] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < rsize; ++i) {
            for (int j = 0; j < csize; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j+1] = 0;
                    continue;
                }
                if (dp[j] != 0 && dp[j+1] != 0) {
                    dp[j+1] += dp[j];
                } else if (dp[j+1] == 0 && dp[j] != 0) {
                    dp[j+1] = dp[j];
                }
            }
        }
        return dp[csize];
    }
};

#endif //LEETCODE_TEST_63_H
