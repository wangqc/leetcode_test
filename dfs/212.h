//
// Created by 王秋城 on 2021/4/19.
//

#ifndef LEETCODE_TEST_212_H
#define LEETCODE_TEST_212_H

#include "../common.h"

class Solution {
public:
    struct TrieNode {
        string word = "";
        vector<TrieNode*> nodes;
        TrieNode() : nodes(26, nullptr) {}
    };

    int rows, cols;
    vector<string> ret;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0) {
            return vector<string>();
        }
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); ++i) {
                int idx = word[i] - 'a';
                if (cur->nodes[idx] == nullptr) {
                    cur->nodes[idx] = new TrieNode();
                }
                cur = cur->nodes[idx];
            }
            cur->word = word;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, root, i, j);
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int row, int col) {
        char c = board[row][col];
        if (c == '#' || root->nodes[c-'a'] == nullptr) {
            return;
        }
        root = root->nodes[c-'a'];
        if (root->word != "") {
            ret.push_back(root->word);
            root->word = "";
        }
        board[row][col] = '#';
        if (row - 1 >= 0)   dfs(board, root, row-1, col);
        if (row + 1 < board.size()) dfs(board, root, row+1, col);
        if (col - 1 >= 0) dfs(board, root, row, col-1);
        if (col + 1 < board[0].size()) dfs(board, root, row, col + 1);
        board[row][col] = c;
    }
};

#endif //LEETCODE_TEST_212_H
