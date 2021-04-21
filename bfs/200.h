//
// Created by 王秋城 on 2021/4/20.
//

#ifndef LEETCODE_TEST_200_H
#define LEETCODE_TEST_200_H

#include "../common.h"

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        grid[r][c] = '0';
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto& p = q.front();
                int r = p.first;
                int c = p.second;
                if (r - 1 >= 0 && grid[r-1][c] == '1') {
                    q.push({r-1,c});
                    grid[r-1][c] = '0';
                }
                if (c - 1 >= 0 && grid[r][c-1] == '1') {
                    q.push({r, c-1});
                    grid[r][c-1] = '0';
                }
                if (r + 1 < grid.size() && grid[r+1][c] == '1') {
                    q.push({r+1, c});
                    grid[r+1][c] = '0';
                }
                if (c + 1 < grid[0].size() && grid[r][c+1] == '1') {
                    q.push({r, c+1});
                    grid[r][c+1] = '0';
                }
                q.pop();
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class SolutionDfs {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0';
        if (row-1 >= 0) dfs(grid, row-1, col);
        if (col-1 >= 0) dfs(grid, row, col-1);
        if (row + 1 < grid.size()) dfs(grid, row + 1, col);
        if (col + 1 < grid[0].size()) dfs(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

#endif //LEETCODE_TEST_200_H
