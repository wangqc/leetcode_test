//
// Created by wangqiucheng on 2020/9/9.
//

#ifndef LEETCODE_TEST_200_H
#define LEETCODE_TEST_200_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int r_size = grid.size();
        int c_size = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') {
            dfs(grid, r-1, c);
        }
        if (r + 1 < r_size && grid[r+1][c] == '1') {
            dfs(grid, r+1, c);
        }
        if (c-1 >= 0 && grid[r][c-1] == '1') {
            dfs(grid, r, c-1);
        }
        if (c+1 < c_size && grid[r][c+1] == '1') {
            dfs(grid, r, c+1);
        }
    }

    // dfs version
    int numIslands(vector<vector<char>>& grid) {
        int i_size = grid.size();
        if (i_size == 0) {
            return 0;
        }
        int j_size = grid[0].size();
        int count = 0;
        for (int i = 0; i < i_size; ++i) {
            for (int j = 0; j < j_size; ++j) {
                if (grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        int r_size = grid.size();
        int c_size = grid[0].size();
        queue<pair<int, int>> pos_que;

        grid[r][c] = '0';
        pos_que.push(make_pair(r, c));
        while (!pos_que.empty()) {
            int que_size = pos_que.size();
            for (int i = 0; i < que_size; ++i) {
                pair<int, int> pr = pos_que.front();
                int row = pr.first;
                int col = pr.second;
                pos_que.pop();
                if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                    grid[row-1][col] = '0';
                    pos_que.push(make_pair(row - 1, col));
                }
                if (row + 1 < r_size && grid[row + 1][col] == '1') {
                    grid[row+1][col] = '0';
                    pos_que.push(make_pair(row + 1, col));
                }
                if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                    grid[row][col-1] = '0';
                    pos_que.push(make_pair(row, col-1));
                }
                if (col + 1 < c_size && grid[row][col + 1] == '1') {
                    grid[row][col+1] = '0';
                    pos_que.push(make_pair(row, col + 1));
                }
            }
        }
    }


    // bfs version
    int numIslandsV2(vector<vector<char>>& grid) {
        int r_size = grid.size();
        if (r_size == 0) return 0;
        int c_size = grid[0].size();

        int count = 0;
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (grid[r][c] == '1') {
                    count++;
                    bfs(grid, r, c);
                }
            }
        }
        return count;
    }
};

#endif //LEETCODE_TEST_200_H
