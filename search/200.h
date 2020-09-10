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
        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
            dfs(grid, r - 1, c);
        }
        if (r + 1 < r_size && grid[r + 1][c] == '1') {
            dfs(grid, r + 1, c);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
            dfs(grid, r, c - 1);
        }
        if (c + 1 < c_size && grid[r][c + 1] == '1') {
            dfs(grid, r, c + 1);
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
                    count++;
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
                    grid[row - 1][col] = '0';
                    pos_que.push(make_pair(row - 1, col));
                }
                if (row + 1 < r_size && grid[row + 1][col] == '1') {
                    grid[row + 1][col] = '0';
                    pos_que.push(make_pair(row + 1, col));
                }
                if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                    grid[row][col - 1] = '0';
                    pos_que.push(make_pair(row, col - 1));
                }
                if (col + 1 < c_size && grid[row][col + 1] == '1') {
                    grid[row][col + 1] = '0';
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

    class UnionFind {
    public:
        UnionFind(vector<vector<char>>& grid) {
            count = 0;
            int r_size = grid.size();
            int c_size = grid[0].size();

            for (int r = 0; r < r_size; ++r) {
                for (int c = 0; c < c_size; ++c) {
                    int idx = r * c_size + c;
                    if (grid[r][c] == '1') {
                        parents.push_back(idx);
                        count++;
                    } else {
                        parents.push_back(-1);
                    }
                    rank.push_back(0);
                }
            }
        }

        // only when grid[r][c] is '1' to call, so parents[x] not -1
        int find(int x) {
            if (parents[x] != x) {
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }

        void connect(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x != root_y) {
                if (rank[root_x] < rank[root_y]) {
                    swap(root_x, root_y);
                }
                parents[root_y] = root_x;
                if (rank[root_x] == rank[root_y]) {
                    rank[root_x]++;
                }
                count--;
            }
        }

        int get_count() {
            return count;
        }

    private:
        vector<int> parents;
        vector<int> rank;
        int count;
    };

    int numIslandsV3(vector<vector<char>>& grid) {
        int r_size = grid.size();
        if (r_size == 0) {
            return 0;
        }
        int c_size = grid[0].size();

        UnionFind unionFind(grid);
        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] == '0';
                    if (r + 1 < r_size && grid[r + 1][c] == '1') {
                        unionFind.connect(r * c_size + c, (r + 1) * c_size + c);
                    }
                    if (c + 1 < c_size && grid[r][c + 1] == '1') {
                        unionFind.connect(r * c_size + c, r * c_size + c + 1);
                    }
                }
            }
        }
        return unionFind.get_count();
    }

};

#endif //LEETCODE_TEST_200_H
