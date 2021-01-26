//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_79_H
#define LEETCODE_TEST_79_H

// 比较复杂的解法记录在search中，还是这边比较可取
// https://leetcode-cn.com/problems/word-search/

// 同时为了剪枝，可以设置一个访问过的位置，防止重复访问

#include "../common.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return false;
        }
        int height = board.size();
        int width = board[0].size();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (back_trace(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool back_trace(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if (word[idx] != board[row][col]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        char tmp = board[row][col];
        board[row][col] = '#';

        bool res = ((row - 1 >= 0 && back_trace(board, word, idx + 1, row - 1, col)) ||
                (row + 1 < board.size() && back_trace(board, word, idx + 1, row + 1, col)) ||
                (col - 1 >= 0 && back_trace(board, word, idx + 1, row, col - 1)) ||
                (col + 1 < board[0].size() && back_trace(board, word, idx + 1, row, col + 1)));
        board[row][col] = tmp;
        return res;
    }
};


#endif //LEETCODE_TEST_79_H
