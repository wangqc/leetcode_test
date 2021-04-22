//
// Created by 王秋城 on 2021/4/22.
//

#ifndef LEETCODE_TEST_693_H
#define LEETCODE_TEST_693_H

#include "../common.h"

class Solution {
public:
    int max = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                queue<pair<int, int>> q;
                grid[i][j] = 0;
                int cur = 1;
                q.push({i,j});
                while (!q.empty()) {
                    int size = q.size();
                    for (int k = 0; k < size; ++k) {
                        auto& p = q.front();
                        int r = p.first;
                        int c = p.second;
                        if (r - 1 >= 0 && grid[r-1][c] == 1) {
                            cur++;
                            grid[r-1][c] = 0;
                            q.push({r-1, c});
                        }
                        if (c - 1 >= 0 && grid[r][c-1] == 1) {
                            cur++;
                            grid[r][c-1] = 0;
                            q.push({r, c-1});
                        }
                        if (r + 1 < grid.size() && grid[r+1][c] == 1) {
                            cur++;
                            grid[r+1][c] = 0;
                            q.push({r+1, c});
                        }
                        if (c + 1 < grid[0].size() && grid[r][c+1] == 1) {
                            cur++;
                            grid[r][c+1] = 0;
                            q.push({r, c+1});
                        }
                        q.pop();
                    }
                    if (cur > max) {
                        max = cur;
                    }
                }
            }
        }
        return max;
    }
};

class SolutionDfs {
public:
    int max = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int& cur) {
        if (grid[x][y] == 0) {
            return;
        }
        cur++;
        grid[x][y] = 0;
        if (x - 1 >= 0) dfs(grid, x - 1, y, cur);
        if (y - 1 >= 0) dfs(grid, x, y - 1, cur);
        if (x + 1 < grid.size()) dfs(grid, x + 1, y, cur);
        if (y + 1 < grid[0].size()) dfs(grid, x, y + 1, cur);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    dfs(grid, i, j, cur);
                    if (cur > max) {
                        max = cur;
                    }
                }
            }
        }
        return max;
    }
};

#endif //LEETCODE_TEST_693_H
