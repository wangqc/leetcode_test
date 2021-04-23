//
// Created by 王秋城 on 2021/4/23.
//

#ifndef LEETCODE_TEST_994_H
#define LEETCODE_TEST_994_H

#include "../common.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        bool has_orange = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    has_orange = true;
                }
            }
        }
        if (q.empty()) {
            return has_orange ? -1 : 0;
        }
        vector<pair<int, int>> dirs({{1,0}, {0, 1}, {-1, 0}, {0, -1}});
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto& p = q.front();
                int r = p.first;
                int c = p.second;
                for (int j = 0; j < 4; ++j) {
                    int new_r = r + dirs[j].first;
                    int new_c = c + dirs[j].second;
                    if (new_r < 0 || new_r >= grid.size()) {
                        continue;
                    }
                    if (new_c < 0 || new_c >= grid[0].size()) {
                        continue;
                    }
                    if (grid[new_r][new_c] == 1) {
                        grid[new_r][new_c] = 2;
                        q.push({new_r, new_c});
                    }
                }
                q.pop();
            }
            if (!q.empty()) {
                cnt++;
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i]][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt;
    }
};

#endif //LEETCODE_TEST_994_H
