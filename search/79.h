//
// Created by 王秋城 on 2021/1/26.
//

#ifndef LEETCODE_TEST_79_H
#define LEETCODE_TEST_79_H

#include "../common.h"

// 比较直观的解法记录于back_trace中
// https://leetcode-cn.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return false;
        }
        unordered_map<char, unordered_set<int>> c_2_pos;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int pos = i * max_len + j;
                auto& st = c_2_pos[board[i][j]];
                st.insert(pos);
            }
        }
        for (auto& c : word) {
            if (c_2_pos.find(c) == c_2_pos.end()) {
                return false;
            }
        }
        bool found = false;
        unordered_set<int> steped_path;
        for (auto& pos : c_2_pos[word[0]]) {
            steped_path.insert(pos);
            back_trace(c_2_pos, word, 1, pos, found, steped_path);
            steped_path.erase(pos);
        }
        return found;
    }

private:
    const int max_len = 200;
    const vector<int> directions{max_len, 1, -max_len, -1};

    void back_trace(const unordered_map<char, unordered_set<int>>& c_2_pos, const string& word, int idx, int cur_pos,
                    bool& found, unordered_set<int>& steped_path) {
        if (found) {
            return;
        }
        if (idx >= word.size()) {
            found = true;
            return;
        }
        const auto& pos_st = c_2_pos.at(word[idx]);
        for (auto& direction : directions) {
            int next_pos = cur_pos + direction;
            if (pos_st.find(next_pos) != pos_st.end() && steped_path.find(next_pos) == steped_path.end()) {
                steped_path.insert(next_pos);
                back_trace(c_2_pos, word, idx + 1, next_pos, found, steped_path);
                steped_path.erase(next_pos);
            }
        }
    }


};

#endif //LEETCODE_TEST_79_H
