//
// Created by 王秋城 on 2021/4/22.
//

#ifndef LEETCODE_TEST_INTERVIEW_16_19_H
#define LEETCODE_TEST_INTERVIEW_16_19_H

#include "../common.h"

class SolutionDfs {
public:
    void dfs(vector<vector<int>>& land, int x, int y, int& cur) {
        if (land[x][y] != 0) {
            return;
        }
        cur++;
        land[x][y] = 1;
        if (x - 1 >= 0) {
            dfs(land, x - 1, y, cur);
            if (y - 1 >= 0) {
                dfs(land, x - 1, y - 1, cur);
            }
            if (y + 1 < land[0].size()) {
                dfs(land, x - 1, y + 1, cur);
            }
        }
        if (x + 1 < land.size()) {
            dfs(land, x + 1, y, cur);
            if (y - 1 >= 0) {
                dfs(land, x + 1, y - 1, cur);
            }
            if (y + 1 < land[0].size()) {
                dfs(land, x + 1, y + 1, cur);
            }
        }


        if (y - 1 >= 0) dfs(land, x, y - 1, cur);
        if (y + 1 < land[0].size()) dfs(land, x, y + 1, cur);
    }

    multiset<int> pond_sizes;
    vector<int> pondSizes(vector<vector<int>>& land) {
        if (land.empty() || land[0].empty()) {
            return vector<int>();
        }
        int rows = land.size();
        int cols = land[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] == 0) {
                    int cur = 0;
                    dfs(land, i, j, cur);
                    pond_sizes.insert(cur);
                }
            }
        }
        vector<int> ret(pond_sizes.begin(), pond_sizes.end());
        return ret;
    }
};

#endif //LEETCODE_TEST_INTERVIEW_16_19_H
