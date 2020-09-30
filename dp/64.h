//
// Created by wangqiucheng on 2020/9/30.
//

#ifndef LEETCODE_TEST_64_H
#define LEETCODE_TEST_64_H

#include <vector>

using namespace std;

class Solution {
public:
    // o(n2)空间
    int minPathSum(vector<vector<int>>& grid) {
        int rsize = grid.size();
        if (rsize == 0) {
            return 0;
        }
        int csize = grid[0].size();
        vector<vector<int>> dp(rsize, vector<int>(csize, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rsize; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int j = 1; j < csize; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for (int i = 1; i < rsize; ++i) {
            for (int j = 1; j < csize; ++j) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }

        return dp[rsize-1][csize-1];
    }

    int minPathSumV2(vector<vector<int>>& grid) {
        int rsize = grid.size();
        if (rsize == 0) {
            return 0;
        }
        int csize = grid[0].size();
        vector<int> dp(csize, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < csize; ++j) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        for (int i = 1; i < rsize; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < csize; ++j) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[csize-1];
    }

    // 可以直接在原有上修改, 那连空间都不需要了
    int minPathSumV3(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    grid[i][j] += grid[i][j-1];
                } else if (j == 0) {
                    grid[i][j] += grid[i-1][j];
                } else {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

#endif //LEETCODE_TEST_64_H
