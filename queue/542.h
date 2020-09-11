//
// Created by wangqiucheng on 2020/9/11.
//

#ifndef LEETCODE_TEST_542_H
#define LEETCODE_TEST_542_H

#include <vector>
#include <queue>

using namespace std;


// TODO: not finish
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r_size = matrix.size();
        if (r_size == 0) {
            return vector<vector<int>>();
        }
        int c_size = matrix[0].size();
        vector<vector<int>> ret(r_size, vector<int>(c_size, 0));

        for (int r = 0; r < r_size; ++r) {
            for (int c = 0; c < c_size; ++c) {
                if (matrix[r][c] == 0) {
                    ret[r][c] = 0;
                    continue;
                }

            }
        }

    }
};

#endif //LEETCODE_TEST_542_H
