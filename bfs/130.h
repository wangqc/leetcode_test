//
// Created by 王秋城 on 2021/4/20.
//

#ifndef LEETCODE_TEST_130_H
#define LEETCODE_TEST_130_H

#include "../common.h"

class SolutionBfs {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][cols-1] == 'O') {
                q.push({i, cols-1});
            }
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') {
                q.push({0, j});
            }
            if (board[rows-1][j] == 'O') {
                q.push({rows-1, j});
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto& p = q.front();
                int r = p.first;
                int c = p.second;
                board[r][c] = 'A';
                if (r-1 >= 0 && board[r-1][c] == 'O') {
                    q.push({r-1, c});
                }
                if (c-1 >= 0 && board[r][c-1] == 'O') {
                    q.push({r, c-1});
                }
                if (r+1 < board.size() && board[r+1][c] == 'O') {
                    q.push({r+1, c});
                }
                if (c+1 < board[0].size() && board[r][c+1] == 'O') {
                    q.push({r, c+1});
                }
                q.pop();
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

class SolutionDfs {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }
        board[row][col] = _mark;
        if (row - 1 >= 0) dfs(board, row - 1, col);
        if (row + 1 < board.size()) dfs(board, row + 1, col);
        if (col - 1 >= 0) dfs(board, row, col - 1);
        if (col + 1 < board[0].size()) dfs(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
             return;
        }
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int i = 0; i < cols; ++i) {
            dfs(board, 0, i);
            dfs(board, rows - 1, i);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == _mark) {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    const char _mark = '#';
};

#endif //LEETCODE_TEST_130_H
