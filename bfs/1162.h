//
// Created by 王秋城 on 2021/4/22.
//

#ifndef LEETCODE_TEST_1162_H
#define LEETCODE_TEST_1162_H

#include "../common.h"

class Solution {
public:
    int max = -1;

    bool pos_valid(vector<vector<int>>& grid, int i, int j) {
        return (i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size());
    }

    bool is_island(vector<vector<int>>& grid, int i, int j) {
        return pos_valid(grid, i, j) && (grid[i][j] == 1);
    }

    int maxDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << i << "," << j << endl;
                if (grid[i][j] == 1) {
                    continue;
                }
                int cur_min = -1;
                for (int d = 1; d <= rows + cols - 2; ++d) {
                    for (int k = 0; k <= d; ++k) {
                        if (is_island(grid, i-k, j-d+k) || is_island(grid, i-k, j+d-k) ||
                                is_island(grid, i+k, j+d-k) || is_island(grid, i+k, j-d+k)) {
                            cur_min = d;
                            d = rows + cols;
                            break;
                        }
                    }
                }
                if (cur_min == -1) {
                    return -1;
                } else if (cur_min > max) {
                    max = cur_min;
                }
            }
        }
        return max;
    }
};

#endif //LEETCODE_TEST_1162_H
