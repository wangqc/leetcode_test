//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_542_H
#define LEETCODE_TEST_542_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// TODO: not finish
class Solution {
public:
    // 第一版本: 普通的bfs遍历
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r_size = matrix.size();
        if (r_size == 0) {
            return vector<vector<int>>();
        }
        int c_size = matrix[0].size();
        vector<vector<int>> ret(r_size, vector<int>(c_size, 0));

        queue<pair<int, int>> que;
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (matrix[r][c] == 0) {
                    que.push(make_pair(r, c));
                }
            }
        }

        int dist = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int r = que.front().first;
                int c = que.front().second;
                que.pop();
                if (r - 1 >= 0 && matrix[r-1][c] == 1 && ret[r-1][c] == 0) {
                    ret[r-1][c] = dist;
                    que.push(make_pair(r-1, c));
                }
                if (r + 1 < r_size && matrix[r+1][c] == 1 && ret[r+1][c] == 0) {
                    ret[r+1][c] = dist;
                    que.push(make_pair(r+1, c));
                }
                if (c - 1 >= 0 && matrix[r][c-1] == 1 && ret[r][c-1] == 0) {
                    ret[r][c-1] = dist;
                    que.push(make_pair(r, c-1));
                }
                if (c + 1 < c_size && matrix[r][c+1] == 1 && ret[r][c+1] == 0) {
                    ret[r][c+1] = dist;
                    que.push(make_pair(r, c+1));
                }
            }
            dist++;
        }
        return ret;
    }


    void dfs(const vector<vector<int>>& matrix, vector<vector<int>>& mem, int i, int j) {
        cout << i << "," << j << "," << mem[i][j] << endl;
        if (i > matrix.size() || j > matrix[0].size()) {
            return;
        }
        if (mem[i][j] != INT32_MAX) {
            return;
        }
        if (matrix[i][j] == 0) {
            mem[i][j] = 0;
            return;
        }
        dfs(matrix, mem, i + 1, j);
        dfs(matrix, mem, i, j+1);
        int min = INT32_MAX;
        if (i - 1 >= 0 && mem[i-1][j] < min) {
            min = mem[i-1][j];
        }
        if (j - 1 >= 0 && mem[i][j-1] < min) {
            min = mem[i][j-1];
        }
        if (i + 1 < matrix.size() && mem[i+1][j] < min) {
            min = mem[i+1][j];
        }
        if (j + 1 < matrix[0].size() && mem[i][j+1] < min) {
            min = mem[i][j+1];
        }
        mem[i][j] = min + 1;
    }

    // 动态规划版本
    vector<vector<int>> updateMatrixV2(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), INT32_MAX / 2));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][j] == 0) {
                    mem[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                mem[i][j] =
            }
        }
        return mem;
    }
};

#endif //LEETCODE_TEST_542_H
